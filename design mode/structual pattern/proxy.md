##代理(proxy)模式

```
class Graphic {
public:
    virtual ~Graphic();
    
    virtual void Draw(const Point& at) = 0;
    virtual void HandleMouse(Event& event) = 0;
    
    virtual const Point& GetExtent() = 0;
    
    virtual void Load(istream& from) = 0;
    virtual void Save(ostream& to) = 0;    

protected:
    Graphic();
};

class Image : public Graphic {
public:
    Image(const char* file);
    virtual ~Image();
    
    virtual void Draw(const Point& at);
    virtual void HandleMouse(Event& event);
    
    virtual const Point& GetExtent();
    
    virtual void Load(istream& from);
    virtual void Save(ostream& to);  
private:
//...
};

class ImageProxy : public Graphic {
public:
    ImageProxy(const char* imageFile);
    virtual ~ImageProxy();
    
    virtual void Draw(const Point& at);
    virtual void HandleMouse(Event& event);
    
    virtual const Point& GetExtent();
    
    virtual void Load(istream& from);
    virtual void Save(ostream& to);
protected:
    Image* GetImage();
private:
    Image* _image;
    Point _extent;
    char* _fileName;  
};

ImageProxy::ImageProxy(const char* fileName) {
    _fileName = strdup(fileName); //copy from fileName, use free release space at last;
    _extent = Point::Zero;
    _image = 0;
}

Image* ImageProxy::GetImage() {
    if(_image == 0) {
        _image = new Image(_fileName);
    }
    return _image;
}

const Point& ImageProxy::GetExtent() {
    if(_extent == Point::Zero) {
        _extent = GetImage()->GetExtent();
    }
    return _extent;
}

void ImageProxy::Draw(const Point& at) {
    GetImage()->Draw(at);
}

void ImageProxy::HandleMouse(Event& event) {
    GetImage()->HandleMouse(event);
}

void ImageProxy::Save(ostream& to) {
    to << _extent << _fileName;
}

void ImageProxy::Load(istream& from) {
    from >> _extent >> _fileName;
}

//last we assumption a TextDocument class ,it contains a Graphic
class TextDocument {
public:
    TextDocument();
    
    void Insert(Graphic*);
    //...
};

//now ,we maybe insert ImageProxy to text using follow method:
TextDocument* text = new TextDocument;
//...
text->Insert(new ImageProxy("anImageFileName"));
```

1. 以下是可以使用Proxy代理模式处理的情况
 - 创建开销大的对象时候，比如显示一幅大的图片时，我们将这个创建的过程交给代理
   去完成，GoF称为虚代理(virtual proxy)；
 - 为网络上的对象创建一个局部的本地代理，比如要操作一个网络上的一个对象（网络
   性能不好的时候，问题尤其突出），我们将这个操纵的过程交给一个代理去完成，GoF
   称为远程代理(remote proxy)；
 - 对对象进行控制访问的时候，比如论坛中不同权限的用户（如管理员、普通用户等）将
   获得不同层次的操作权限，我们将这个工作交给一个代理去完成，GoF称为保护代理
   （protection proxy）；
 - 智能指针（smart pointer）；