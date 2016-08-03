//QGis样式设置包含在qgisappstylesheet.cpp中，buildStyleSheet方法记录了该样式设置的具体方式。

qgsmessagebaritem.cpp文件中定义了各种弹出对话框的样式，包括information/warning/critical，以及下面的文字编辑框的样式设置
mTextEdit->setStyleSheet( "QTextEdit { background-color: rgba(0,0,0,0); margin-top: 0.25em; max-height: 1.75em; min-height: 1.75em; } "
                                "QScrollBar { background-color: rgba(0,0,0,0); } "
                                "QScrollBar::add-page,QScrollBar::sub-page,QScrollBar::handle { background-color: rgba(0,0,0,0); color: rgba(0,0,0,0); } "
                                "QScrollBar::up-arrow,QScrollBar::down-arrow { color: rgb(0,0,0); } " );