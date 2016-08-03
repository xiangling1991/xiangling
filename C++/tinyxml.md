##TiXmlBase类：是所有类的基类，被TiXmlNode、TiXmlAttribute继承

###TiXmlNode：所有的被<...>...<...>包括的内容，而xml中的节点又具体分为以下几方面：声明、注释、节点以及节点间的文本
###TiXmlNode ==>>TiXmlComment/TiXmlDeclaration/TiXmlDocument/TiXmlElement/TiXmlText/TiXmlUnknown(继承)
###TiXmlAttribute:表示尖括号里面的内容，比如<...\*\*\*=...>，其中"\*\*\*"就是一个属性。

                                                            <!--  #->TiXmlDocment 整个文档-->
#<xml>
<?xml version="1.0" encoding="UTF-8"?>                      <!--  #->TiXmlDeclaration-->
<phonebook>         
    <!--one item behalfs one contacted person.-->           <!-- #->TiXmlComment-->
    <item>                                                  <!-- #->TiXmlElement-->
        <name>miaomaio</name>                                 
    <addr>Shaanxi Xi'an</addr>  
    <tel>13759911917</tel>  
    <email>miaomiao@home.com</email>  
    </item>  
    <item>  
        <name>gougou</name>  
    <addr>Liaoning Shenyang</addr>  
    <tel>15840330481</tel>  
    <email>gougou@home.com</email>  
    </item>  
    <!--more contacted persons.-->  
</phonebook>  
#<xml>

// 读者对象：对TinyXml有一定了解的人。本文是对TinyXml工具的一些知识点的理解。
// 1  TinyXml中对TiXmlNode进行了分类，是用一个枚举进行描述的。
// enum NodeType
// {
// DOCUMENT,    文档节点
// ELEMENT,     元素节点
// COMMENT,     还没弄清楚
// UNKNOWN,     未知节点
// TEXT,        文本节点
// DECLARATION, 声明节点
// TYPECOUNT    还没弄清楚
// };
// TiXmlNode * pNode->Type() 函数可以返回节点的类型。
// 枚举的比较方法：TiXmlText::TEXT == pNode->Type();
// 
// 这几个类型非常重要，尤其是在遍历xml时或者查找一个节点时
// 我对节点和元素的理解如下：为了说明问题，我使用下面的xml文档来举例说明
// <?xml version="1.0" encoding="gb2312"?>
// <Persons>	
// 	<person Id="200" Shengao=34 ClassName="计本0508">
// 		<name>vertor</name>
// 		<age>20</age>
// 		<address encode="utf-8">
// 			<country>中国</country>
// 			<province>山西</province>
// 			<village>王大庄</village>
// 		</address>
// 	</person>
// </Persons>
// 
// 2.1 节点：一种对文档结构的描述对象
// 2.2 元素：对文档某一个数据块的描述
// 2.3 文本是指没有孩子的节点
//    例如<village>大王庄</village>  文本节点是："大王庄" 
//    然而判断一个节点是否是文本节点时并不是根据pNode->NoChildren()来判断，而是根据节点的类型来判断
//    因为如果一个节点形如：<village></village>它也是没有孩子节点的。
// 2.4 节点类可以转换成元素对象。
//     例如 TiXmlElement * pElement = pNode->ToElement();
//     那什么时候需要转换成元素呢？
//       当你需要元素的一些属性值是就需要转换了。
// 2.5 元素跟节点都有关于访问孩子的函数，
// 元素访问孩子的函数：
//   FirstChildElement() 返回当前元素的孩子元素
//   NextSiblingElement() 返回当前元素的同级元素
// 节点访问节点孩子的函数：
//   FirstChild()		返回当前节点的孩子节点
//   NextSibing()		返回当前节点的同级下一个节点
// 个人觉得 元素访问和节点访问在一般的访问下没有区别，两者都可以访问的孩子
// 对于一些特殊的情况下才需要区分。比如你要访问属性时，就需要用元素来找到第一个属性值。
// 2.6 对于遍历一个xml文档时，思路一般是这样的：
//   1 载入一个xml
//   2 获得根元素（不是根节点）
//   3 循环访问每一个根元素的子元素
//   4 对每一个子元素进行解析。
// 	4.1 获取子元素的类型Type
// 	4.2 switch(Type)
// 	    case TEXT:
// 		输出文本节点的值pNode->value()
// 	    case ELEMENT:
// 	        获取元素的value(这里的value指的是元素的名字，例如：person元素）
// 		循环获取元素的每一个属性
// 		    a 得到元素的第一个属性
// 		    b do——while循环获取每一个属性和值。
// 	    case COMMENT: 暂时不用管
// 	    case UNKNOWN: 暂时不用管
// 	    case DECLARATION: 
// 	         获取元素的版本，编码方式等等
// 	4.3 循环遍历子元素的下一级元素（即孙子元素) 在这里也可以遍历孙子节点。
// 	    递归调用第四步。
// 基本思路就是这样，具体代码见后面
// 2.7 如果定位一个节点
//   唯一确定一个节点的方法是根据节点名，属性名，属性值
//   1 根据xml的遍历思想找到与给定节点名一样的节点
//   2 如果这个节点有属性并且属性名和值与给定的一致，说明找到了。
//   3 如果没有一致的，说明解析失败。
//   4 如果没有给定属性名和值，则可以默认只查找与节点名一致的节点。
// 2.8 编码问题
//   用TinyXml加载一个xml文档时，根据文档的编码方式来加载，在操作过程中需要进行编码转换
//   如果encoding=utf-8 则在遍历时，需要进行编码转换，具体转换还没找到方法。
// 
// 2.9 指针的 new和释放。
//    TinyXml已经帮我们把指针分配的内存进行了管理，在析构函数中进行了处理，我们不需要处理new出来的指针
//    如果我们显示的delete时，有可能影响程序运行。
// 3.0 对于添加一个节点，删除一个节点，更新一个节点时，都需要在最后SaveFile,我就好几次忘了SaveFile，所以调了老半天。
// 3.1 总的来说，Tinyxml还是不错的，以后继续学习。
// 部分功能代码
// 3.2 对于插入一个节点，首先获取要插入节点的父节点，然后进行插入，最需要注意的是在查询父节点的是时候，必须对应同一个文本对象来操作。有可能在两个函数中同时打开了同一个xml文档，虽然名字一样，但是不是同一个xmldocument对象，所以操作会失败。
// 最后要保存。

#include "XmlTest.h"

#define MAX_NUM 256

/************************************************************************/
/*  创建一个xml文档                                                                    */
/************************************************************************/
void createXml(const char * ccXmlName)
{
	
	//创建一个XML的文档对象。
    TiXmlDocument *myDocument = new TiXmlDocument();
	TiXmlDeclaration* decl = new TiXmlDeclaration("1.0","gb2312","yes");
	myDocument->LinkEndChild(decl);

    //创建一个根元素并连接。
    TiXmlElement *RootElement = new TiXmlElement("Persons");
    myDocument->LinkEndChild(RootElement);
    
	for(int i=0; i<10;i++)
	{
		//创建一个Person元素并连接。
		TiXmlElement *PersonElement = new TiXmlElement("Person");
		RootElement->LinkEndChild(PersonElement);
	    
		//设置Person元素的属性。
		PersonElement->SetAttribute("ID", i);
		
		//创建name元素、age元素并连接。
		TiXmlElement *NameElement = new TiXmlElement("name");
		TiXmlElement *AgeElement = new TiXmlElement("age");
		PersonElement->LinkEndChild(NameElement);
		PersonElement->LinkEndChild(AgeElement);
	    
		//设置name元素和age元素的内容并连接。
		TiXmlText *NameContent = new TiXmlText("周星星");
		TiXmlText *AgeContent = new TiXmlText("20");
		NameElement->LinkEndChild(NameContent);
		AgeElement->LinkEndChild(AgeContent);

	}

    //保存到文件
     myDocument->SaveFile(ccXmlName);
}

/************************************************************************/
/*  遍历一个xml文档                                                                   */
/************************************************************************/
void readXml(const char * ccXmlName)
{
	//创建一个XML的文档对象。
	TiXmlDocument *myDocument = new TiXmlDocument(ccXmlName);
	myDocument->LoadFile();

	//获得xml的头，即声明部分
	TiXmlDeclaration* decl = myDocument->FirstChild()->ToDeclaration();
	cout << "xml文件的版本是:" << decl->Version() << endl;
	cout << "xml的编码格式是：" << decl->Encoding() << endl;

	//获得根元素
	TiXmlElement *RootElement = myDocument->RootElement();

	//输出根元素名称
	cout << RootElement->Value() << endl;

	TiXmlNode* pNode  = NULL;
	string msg = "";

	for(pNode=RootElement->FirstChildElement();pNode;pNode=pNode->NextSiblingElement())
	{
		msg += dumpNode(pNode,0);
	}

	cout << msg << endl;
}


/************************************************************************/
/*描述：遍历一个元素
  时间：2012-9-18
  参数说明：pNode节点，flag 节点嵌套层数
/************************************************************************/
string dumpNode(TiXmlNode * pNode,int flag)
{	
	string msg = "";
	
	if(pNode == NULL)
	{
		return "";
	}

	TiXmlText * pText = NULL;
	TiXmlNode * pChildNode = NULL;
	int t = pNode->Type();
	
	switch(t)
	{
		//节点类型是text节点
		case TiXmlText::TINYXML_TEXT:
		{	pText = pNode->ToText();
			string text = pText->Value();
			if(!text.empty())
			{
				msg = msg + "="+ text;
			}
			break;
		}

		//节点类型是Element
		case TiXmlText::TINYXML_ELEMENT:
		{
			msg = msg + "\r\n";
			int num = flag;
			
			while(num >= 1)
			{
				msg = msg + "  ";
				num--;
			}
			
			msg = msg + pNode->Value();
			
			//输出属性
			TiXmlElement * pElement = pNode->ToElement();
			
			TiXmlAttribute * pAttr = pElement->FirstAttribute();
			TiXmlAttribute * pNextAttr =NULL;
			string tmpAttrMsg = "[";
			
			//if(pAttr != NULL && !(string(pAttr->Name())).compare("name") && !(string(pAttr->Value())).compare("IDH_CFG_USB"))
			if(pAttr != NULL )
			{	
				string tmpAttrVal = "";
				string tmpAttrName = "";		
				
				do
				{							
					tmpAttrVal = pAttr->Value();
					tmpAttrName = pAttr->Name();
					tmpAttrMsg += tmpAttrName + "=" +tmpAttrVal + ",";	//各个属性之间用逗号分隔
				}while(pAttr = pAttr->Next());
				
				/* 去掉最后的',' */
				tmpAttrMsg = tmpAttrMsg.erase(tmpAttrMsg.find_last_of(","));
				//同上 tmpAttrMsg = tmpAttrMsg.substr(0,tmpAttrMsg.find_last_of(","));
				
			}
			tmpAttrMsg += "]";
			msg += tmpAttrMsg;

			break;
		}

		case TiXmlText::TINYXML_DOCUMENT:
		case TiXmlText::TINYXML_COMMENT:
		case TiXmlText::TINYXML_UNKNOWN:
		case TiXmlText::TINYXML_DECLARATION:
		case TiXmlText::TINYXML_TYPECOUNT:
		{
			;//Nothing to do
		}
	}
	
	//循环访问它的每一个元素
	for(pChildNode=pNode->FirstChild();pChildNode!=0;pChildNode = pChildNode->NextSibling())
	{
		
		msg = msg + dumpNode(pChildNode,flag+1);

	}

	return msg;
}


/************************************************************************/
/* 查询出唯一节点                                                         */
/* 参数说明：
   string nodeName    节点名
   string nodeAttrName 节点的属性
   string nodeAttrValue 节点属性的值
/************************************************************************/
TiXmlNode * SelectSingleNode(const char * cXmlName,string nodeName,string nodeAttrName,string nodeAttrValue)
{
	//加载一个XML的文档对象。

	TiXmlDocument *xmlDoc = new TiXmlDocument(cXmlName);
	if(!xmlDoc->LoadFile())	//是tinyXml会自动处理文档的BOM
	{
		return NULL;
	}


	if(xmlDoc == NULL)
	{
		return NULL;
	}

	//获得根元素
	TiXmlElement *RootElement = xmlDoc->RootElement();
	if(RootElement == NULL)
	{
		cout << "解析错误,无法获取根元素" << endl;
		return NULL;
	}

	TiXmlNode * pNode  = NULL;
	TiXmlNode * pSelectNode = NULL;
	string msg = "";

	for(pNode=RootElement->FirstChildElement();pNode;pNode=pNode->NextSiblingElement())
	{
		
		pSelectNode = selectChildNode(pNode,nodeName,nodeAttrName,nodeAttrValue);
		if(pSelectNode)
		{
			break;
		}
	}
	
	if(pSelectNode)
	{
		cout << "解析成功" << endl;
		cout << "[节点名]=" << pSelectNode->Value() << endl;
		return pSelectNode;
	}
	else
	{
		cout << "解析错误，无法获取节点" << endl;
		return NULL;
	}

}


TiXmlNode * SelectSingleNodeByRootEle(TiXmlElement* RootElement,string nodeName,string nodeAttrName,string nodeAttrValue)
{
	//加载一个XML的文档对象。
	
// 	TiXmlDocument *xmlDoc = new TiXmlDocument(cXmlName);
// 	if(!xmlDoc->LoadFile())	//是tinyXml会自动处理文档的BOM
// 	{
// 		return NULL;
// 	}
// 	
// 	
// 	if(xmlDoc == NULL)
// 	{
// 		return NULL;
// 	}
	
	//获得根元素
	//TiXmlElement *RootElement = xmlDoc->RootElement();
	if(RootElement == NULL)
	{
		cout << "解析错误,无法获取根元素" << endl;
		return NULL;
	}
	
	TiXmlNode * pNode  = NULL;
	TiXmlNode * pSelectNode = NULL;
	string msg = "";
	
	for(pNode=RootElement->FirstChildElement();pNode;pNode=pNode->NextSiblingElement())
	{
		
		pSelectNode = selectChildNode(pNode,nodeName,nodeAttrName,nodeAttrValue);
		if(pSelectNode)
		{
			break;
		}
	}
	
	if(pSelectNode)
	{
		//cout << "解析成功" << endl;
		//cout << pSelectNode->Value() << endl;
		return pSelectNode;
	}
	else
	{
		cout << "解析错误，无法获取节点" << endl;
		return NULL;
	}
	
}


/************************************************************************/
/*
  根据父节点循环遍历查找子节点
  参数说明
    noteName 节点名
	noteAttrName 属性名
	noteAttrValue 属性值
/************************************************************************/
TiXmlNode * selectChildNode(TiXmlNode * pNode,string nodeName,string nodeAttrName,string nodeAttrValue)
{
	if(pNode == NULL)
	{
		return NULL;
	}
	TiXmlNode * pSelectedNode = NULL;
	TiXmlNode * pChildNode = NULL;
	int t = pNode->Type();
	switch (t)
	{
	case TiXmlText::TINYXML_DOCUMENT:
	case TiXmlText::TINYXML_DECLARATION:
	case TiXmlText::TINYXML_TEXT:
	case TiXmlText::TINYXML_UNKNOWN:
	case TiXmlText::TINYXML_COMMENT:
		break;
	case TiXmlText::TINYXML_ELEMENT:
	if(pNode->Value() == nodeName)
	{
			//cout << pNode->Value() << endl;
			if(!nodeAttrName.empty() && !nodeAttrValue.empty())
			{
				TiXmlElement * pElement = pNode->ToElement();

				TiXmlAttribute * pAttr = pElement->FirstAttribute();
				TiXmlAttribute * pNextAttr =NULL;
				if(pAttr != NULL)
				{	
					do
					{							
						if(pAttr->Name()==nodeAttrName&&pAttr->Value()== nodeAttrValue)
						{
							//cout << pAttr->Value() << endl;
							return pNode;
						}
					}while(pAttr = pAttr->Next());
				}
			}
			else
			{
				return pNode;
			}
			
		}
		else
		{
			//循环访问它的每一个元素
			for(pChildNode=pNode->FirstChild();
				pChildNode!=0;
				pChildNode = pChildNode->NextSibling())
			{
				pSelectedNode = selectChildNode(
									pChildNode,
									nodeName,
									nodeAttrName,
									nodeAttrValue);
				if(pSelectedNode)
				{
					return pSelectedNode;
				}
			}
		}

	default:break;
	}
	return NULL;
}



/************************************************************************/
/* 普通插入一个节点，还不完善。                                                               */
/************************************************************************/
bool insert(const char * ccXmlName)
{
	//加载一个XML的文档对象。
	TiXmlDocument *myDocument = new TiXmlDocument(ccXmlName);
	myDocument->LoadFile();
	
	if(myDocument == NULL)
	{
		return false;
	}
	//获得xml的头，即声明部分
	TiXmlDeclaration* decl = myDocument->FirstChild()->ToDeclaration();
	if(decl != NULL)
	{
		cout << "xml文件的版本是:" << decl->Version() << endl;
		cout << "xml的编码格式是：" << decl->Encoding() << endl;
	}
	

	//获得根元素
	TiXmlElement *RootElement = myDocument->RootElement();
    
	if(RootElement != NULL)
	{

		//创建一个Person元素并连接。
		TiXmlElement *PersonElement = new TiXmlElement("Person");
		PersonElement->SetAttribute("Id",1);
		RootElement->LinkEndChild(PersonElement);  
		
		TiXmlText *textElement = new TiXmlText("Jam");
		PersonElement->LinkEndChild(textElement);
		
		//增加一个team元素
		TiXmlElement *TeamElement = new TiXmlElement("team");
		TeamElement->SetAttribute("TID","001");
		RootElement->LinkEndChild(TeamElement);
		
		//增加team的子节点name
		TiXmlElement *teamName = new TiXmlElement("name");
		TiXmlText *nameText = new TiXmlText("workgroup");
		teamName->LinkEndChild(nameText);
		TeamElement->LinkEndChild(teamName);

		//增加team的子节点type
		TiXmlElement *teamType = new TiXmlElement("type");
		TiXmlText *typeText = new TiXmlText("SI");
		teamType->LinkEndChild(typeText);

		TeamElement->LinkEndChild(teamType);

		myDocument->SaveFile("Person.xml");
		

		//输出根元素名称
		cout << RootElement->Value() << endl;
		return true;
	}
	 return false;
}



/************************************************************************/
/* 获取一个节点的属性                                                  */
/************************************************************************/
string getAttribute(TiXmlNode * pNode)
{
	if(pNode == NULL) return "";
	//输出属性
	string msg = "";
	TiXmlElement * pElement = pNode->ToElement();

	TiXmlAttribute * pAttr = pElement->FirstAttribute();
	TiXmlAttribute * pNextAttr =NULL;
	string tmpAttrMsg = "";

	if(pAttr != NULL)
	{	
		string tmpAttrVal = "";
		string tmpAttrName = "";		

		do
		{							
			tmpAttrVal = pAttr->Value();
			tmpAttrName = pAttr->Name();
			tmpAttrMsg += "[" + tmpAttrName + "]=" + tmpAttrVal+"\n";	//各个属性之间用逗号分隔
		}while(pAttr = pAttr->Next());
		
		//tmpAttrMsg = tmpAttrMsg.erase(tmpAttrMsg.find_last_of(","));
	}

	//tmpAttrMsg += "]";
	msg += tmpAttrMsg;

	return msg;
}




/************************************************************************/
/*	在指定位置插入一个元素												*/
/************************************************************************/
bool insertAElement(const char * cXmlName, TiXmlElement * pElement)
{
	//加载一个XML的文档对象。
	TiXmlDocument *xmlDoc = new TiXmlDocument(cXmlName);
	xmlDoc->LoadFile();

	if(xmlDoc == NULL)
	{
		return false;
	}

	//获得xml的头，即声明部分
	TiXmlDeclaration* decl = xmlDoc->FirstChild()->ToDeclaration();
	if(decl != NULL)
	{
		cout << "xml文件的版本是:" << decl->Version()  << endl;
		cout << "xml的编码格式是:" << decl->Encoding() << endl;
	}
	//获得根元素
	TiXmlElement *RootElement = xmlDoc->RootElement();
	if(RootElement != NULL)
	{
		TiXmlNode * pNode = SelectSingleNode(cXmlName,"name","length","100");
		if(pNode == NULL)
		{
			return false;
		}
		
		//创建一个Person元素并连接。
		TiXmlElement *pNewElement = new TiXmlElement("Person");
		if(pNewElement == NULL)
		{
			return false;
		}
		pNewElement->SetAttribute("Id","1");
		TiXmlText *textElement = new TiXmlText("gbnn");
		if(textElement == NULL)
		{
			return false;
		}
		pNewElement->LinkEndChild(textElement);
		TiXmlNode * pRet = pNode->InsertBeforeChild(pNode->LastChild(),*pNewElement);
		//TiXmlNode * pRet = pNode->LinkEndChild(pNewElement);
		xmlDoc->Print();
		bool b = xmlDoc->SaveFile();
		if(b)
		{
			cout << "添加成功" << endl;
			return b;
		}
		else
		{
			cout << "添加失败" << endl;
			return false;
		}
	}
	else
	{
		return false;
	}
}	

//const char * cXmlName,string strNodeName,string strNodeAttrName,string strNdeAttrValue,string strPath
/*!
*  \Function: 修改一个唯一节点中第二、三属性的值为一子符串
*
*  \param cXmlName       xml文件名
*  \param strNodeName    指定的节点名。
*  \param strNodeAttrName 指定的节点名所在节点中第一属性名。
*  \param strNdeAttrValue 指定的节点名所在节点中第一属性值。
*  \param strPath         字符串。为当前路径名的上一级目录的字符串
*  \return  是否成功。true为成功，false表示失败。
*/
bool ModifySingleNode(const char * cXmlName,string strNodeName,string strNodeAttrName,string strNdeAttrValue,string strPath)
{
	if (strNodeName.empty() || strNodeAttrName.empty() || strNdeAttrValue.empty() ||strPath.empty())
	{
		return false;
	}

	// 定义一个TiXmlDocument类指针
    TiXmlDocument *pDoc = new TiXmlDocument();
    if (NULL==pDoc)
    {
        return false;
    }
	
	pDoc->LoadFile(cXmlName);

	TiXmlElement* pRootElement = pDoc->RootElement();

	TiXmlNode * pNode = SelectSingleNodeByRootEle(pRootElement,strNodeName,strNodeAttrName,strNdeAttrValue);
	
	if (NULL == pNode)
	{
		return false;
	}

	//输出属性
	TiXmlElement * pElement = pNode->ToElement();

	TiXmlAttribute * pAttr = pElement->FirstAttribute();
	TiXmlAttribute * pNextAttr =NULL;
	
	if(pAttr != NULL)
	{	
		string tmpAttrVal = "";
		string tmpAttrName = "";		
		
		do
		{							
			tmpAttrVal = pAttr->Value();
			tmpAttrName = pAttr->Name();
			
			//节点中第一个属性对跳过
			if (tmpAttrName == strNodeAttrName && tmpAttrVal == strNdeAttrValue)
			{
				continue;
			}

			//修改第二和第三个属性对
			if ("href" == tmpAttrName)
			{
				pAttr->SetValue(strPath.c_str());
			}

			if ("test" == tmpAttrName)
			{
				pAttr->SetValue(strPath.c_str());
			}

		}while(pAttr = pAttr->Next());
	}
	
	pDoc->SaveFile("hhhhhhhhhhhhh.xml");
	
	return true;
}

void ShowSingleNode(const char * cXmlName,string strNodeName,string strNodeAttrName,string strNdeAttrValue)
{
	TiXmlNode * pNode = SelectSingleNode(cXmlName,strNodeName,strNodeAttrName,strNdeAttrValue);
	
	if (NULL == pNode)
	{
		return;
	}

	string strTem = getAttribute(pNode);

	cout << strTem.c_str() << endl;
}

string PathOpt()
{
	char cStr[MAX_NUM];
	GetCurrentDirectory(MAX_NUM,cStr);

	string str = cStr;
	
	//取当前路径的上一目录所在路径
	size_t pos = str.find_last_of("\\");
	str.erase(str.begin()+pos,str.end());

	return str;
}


int main()
{
	const char * cXmlName = "files.xml";
	string strPath;
	//createXml(ccXmlName);
	//readXml(cXmlName);
	//insert(ccXmlName);
	//readXml(ccXmlName);

	ShowSingleNode(cXmlName,"Document","title","About VMware Player Help");
	
	strPath = PathOpt();

	bool ret = ModifySingleNode(cXmlName,"Document","title","About VMware Player Help",strPath);

	if (ret)
	{
		cout << "OK" << endl;
	}
	else
	{
		cout << "false" << endl;
	}

	ShowSingleNode("hhhhhhhhhhhhh.xml","Document","title","About VMware Player Help");
	return 0;
}