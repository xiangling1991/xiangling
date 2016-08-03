#ActionContext class

inherits:IActionContext

用来对界面添加action时的操作管理，包括注册action

#IActionContext class

inherits by:ActionContext

This class is a abstract class, it's base class of all action class.

#IManage class

inherits: QObject
inherits by:IActionManager, IToolWindowManager, IDockManager, IProjectManager, IOptionManager, 
            IEditorManager, IFileManager, IMimeTypeManager

This IManager class is base class of all