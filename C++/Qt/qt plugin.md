#Plugins

//将Identifier和classname关联起来
1. Q_DECLARE_INTERFACE( ClassName, Identifier) 

```
const char* BrushInterface_iid = "org.qt-project.Qt.Examples.PlugAndPaint.BrushInterface";

Q_DECLARE_INTERFACE(BrushInterface, BrushInterface_iid)
```

//这个宏告诉qt将要实现的接口
2. Q_INTERFACES(...接口)

```
class BasicToolsPlugin : public QObject,
                         public BrushInterface,
                         public ShapeInterface,
                         public FilterInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.Examples.PlugAndPaint.BrushInterface" FILE "basictools.json")
    Q_INTERFACES(BrushInterface ShapeInterface FilterInterface)

public:
    ...
};
```

//将此类声明为元数据，并当作plugin的一部分
3. Q_PLUGIN_METADATA(...)

```
class MyInstance : public QObject
{
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QDummyPlugin" FILE "mymetadata.json")
};
```

```
//testapi.h

#ifndef TESTAPI
#define TESTAPI

#include <QObject>
#include "ttest_global.h"

class TtestPluginApi : public QObject
{
    Q_OBJECT
public:
    virtual const std::string Test() = 0;
};

class IFactory : public QObject
{
public:
    virtual ~IFactory(){}

    virtual void setPluginName(std::string name) = 0;

    virtual TtestPluginApi* createPlugin() = 0;
};

Q_DECLARE_INTERFACE(IFactory, "xl.test/x1.0")

#endif // TESTAPI
```

```
test.h

#ifndef TTEST_H
#define TTEST_H

#include <QObject>
#include <QtPlugin>
#include "testapi.h"

class Ttest : public TtestPluginApi
{
    Q_OBJECT

public:
    Ttest();

    virtual const std::string Test();
};

template<typename T>
class FactoryImpl : public IFactory
{
public:
    virtual void setPluginName(std::string name)
    {
        this->name = name;
    }

    virtual TtestPluginApi* createPlugin()
    {
        return new T;
    }

private:
    std::string name;
};

class Factory : public FactoryImpl<Ttest>
{
    Q_OBJECT
    Q_INTERFACES(IFactory)
    Q_PLUGIN_METADATA(IID "Ttest")
public:
    Factory(){}
};

#endif // TTEST_H
```

```
//test.cpp

#include "Ttest.h"


Ttest::Ttest()
{
}

const std::string Ttest::Test()
{
    return "Hello World";
}

```