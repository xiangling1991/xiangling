# wfview

ActorElement -->Element
             -->AtomicActor

NoteElement -->Element

TitleElement --> Element

LinkElement -->Element

AtomicActor -->Actor

Actor -->NamedObject
      -->XMLExportable
      -->ScheduleObject
      
三种可定义活动
WorkActorElement -->ActorElement

UserActorElement -->WorkActorElement

ComputeActorElement -->WorkActorElement

四种系统活动(Start End Display Merge)   
SystemActorElement -->ActorElement (start end 两种活动)

DataDisplayActorElement -->SystemActorElement

MergeActorElement -->SystemActorElement

活动添加 删除 复制 粘贴等命令
AddElementCommand -->EditCommand

DeleteElementCommand -->EditCommand

MoveElementCommand -->EditCommand

ShowPropertyCommand -->Command

CopyCommand -->Command

PasteCommand -->Command

EditComman -->Command
        
端口 链接 活动

Port -->NamedObject

PortElement -->Port

三种视图模式
DesignViewMode -->ViewMode

MonitorViewMode -->ViewMode

BrowseViewMode -->ViewMode


用于生成特定的界面（ActorPropertyDlg.h）

BaseControl -->SaveChange
            -->FindTargetParam
            -->wxWindow
            
SetListScalarCtrlDlg -->wxDialog
                     -->SaveChange

SetListScalarCtrl -->BaseControl

DataViewDerivedModel -->wxDataViewListStore

DesignFilterSatImageDlg -->wxDialog
                        -->SaveChange
                        
DataViewSatFileModel -->wxDataViewListStore
                     -->SaveChange

SatFileListSelect -->BaseControl

FileListSelect -->BaseControl

FileSelect -->BaseControl

DirectoryListSelect -->BaseControl

SpatialRefFileSelect -->BaseControl

SelectDirectory -->BaseControl

SetDictionaryDlg -->wxDialog

SetDictionary -->BaseControl

CalculateResolutionDlg -->wxDialog

CellSizeCtrl -->BaseControl

CommonControl -->BaseControl

ChoiceSelect -->BaseControl

NewMathExpressionDlg-->wxDialog

MathExprCtrl -->BaseControl

MathExprListCtrl -->BaseControl

UserParameterPropertyDlg -->wxCollapsiblePane
                         -->SaveChange
                         
SystemParameterPropertyDlg -->wxCollapsiblePane
                           -->SaveChange
                           
ShowPropertyDlg -->wxCollapsiblePane
                -->SaveChange
                
ActorPropertyDlg -->wxDialog



各种数据类型

该方法用于获取数据的类型，如果不存在这种类型，则将该类型注册到类型库中
const TypeInfo* TypeSystem::QueryType(const std::string& name);

BuiltinTypeInitializer类构造时将注册内置的数据类型

该方法用于已注册的内置类型获取各类型数据之间的距离
int GetTypeDistance(const TypeInfo* source, const TypeInfo* target) const;



在集群运行时，可以给实例配置多套运行参数，其中的config参数就是用来添加配置名称，此时会在
数据库的Instance_Config中添加该参数的信息，包括状态。
由数据库中的Workflow_Instance和Instance_Config中对应的xml信息，即可渲染出当前的监控实例。