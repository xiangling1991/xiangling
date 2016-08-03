/********************************************************************************
** Form generated from reading UI file 'FileFilterDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILEFILTERDLG_H
#define UI_FILEFILTERDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_FileFilterDlg
{
public:
    QGridLayout *gridLayout;
    QLineEdit *root_dir_txt;
    QLabel *label_2;
    QLabel *label_3;
    QFrame *line;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QPushButton *all_select_btn;
    QPushButton *clear_btn;
    QPushButton *reverse_btn;
    QPushButton *root_dir_btn;
    QTableWidget *file_list;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *ok_btn;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *cancel_btn;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *file_format_txt;

    void setupUi(QDialog *FileFilterDlg)
    {
        if (FileFilterDlg->objectName().isEmpty())
            FileFilterDlg->setObjectName(QStringLiteral("FileFilterDlg"));
        FileFilterDlg->resize(470, 300);
        gridLayout = new QGridLayout(FileFilterDlg);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        root_dir_txt = new QLineEdit(FileFilterDlg);
        root_dir_txt->setObjectName(QStringLiteral("root_dir_txt"));

        gridLayout->addWidget(root_dir_txt, 0, 1, 1, 1);

        label_2 = new QLabel(FileFilterDlg);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label_3 = new QLabel(FileFilterDlg);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        line = new QFrame(FileFilterDlg);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 4, 0, 1, 2);

        label = new QLabel(FileFilterDlg);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        all_select_btn = new QPushButton(FileFilterDlg);
        all_select_btn->setObjectName(QStringLiteral("all_select_btn"));

        horizontalLayout->addWidget(all_select_btn);

        clear_btn = new QPushButton(FileFilterDlg);
        clear_btn->setObjectName(QStringLiteral("clear_btn"));

        horizontalLayout->addWidget(clear_btn);

        reverse_btn = new QPushButton(FileFilterDlg);
        reverse_btn->setObjectName(QStringLiteral("reverse_btn"));

        horizontalLayout->addWidget(reverse_btn);


        gridLayout->addLayout(horizontalLayout, 3, 1, 1, 1);

        root_dir_btn = new QPushButton(FileFilterDlg);
        root_dir_btn->setObjectName(QStringLiteral("root_dir_btn"));
        root_dir_btn->setMinimumSize(QSize(25, 25));
        root_dir_btn->setMaximumSize(QSize(25, 25));

        gridLayout->addWidget(root_dir_btn, 0, 2, 1, 1);

        file_list = new QTableWidget(FileFilterDlg);
        if (file_list->columnCount() < 2)
            file_list->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        file_list->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        file_list->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        file_list->setObjectName(QStringLiteral("file_list"));

        gridLayout->addWidget(file_list, 2, 1, 1, 2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        ok_btn = new QPushButton(FileFilterDlg);
        ok_btn->setObjectName(QStringLiteral("ok_btn"));

        horizontalLayout_2->addWidget(ok_btn);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        cancel_btn = new QPushButton(FileFilterDlg);
        cancel_btn->setObjectName(QStringLiteral("cancel_btn"));

        horizontalLayout_2->addWidget(cancel_btn);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        gridLayout->addLayout(horizontalLayout_2, 5, 0, 1, 3);

        file_format_txt = new QLineEdit(FileFilterDlg);
        file_format_txt->setObjectName(QStringLiteral("file_format_txt"));

        gridLayout->addWidget(file_format_txt, 1, 1, 1, 1);


        retranslateUi(FileFilterDlg);

        QMetaObject::connectSlotsByName(FileFilterDlg);
    } // setupUi

    void retranslateUi(QDialog *FileFilterDlg)
    {
        FileFilterDlg->setWindowTitle(QApplication::translate("FileFilterDlg", "FileFilterDlg", 0));
        label_2->setText(QApplication::translate("FileFilterDlg", "File Format", 0));
        label_3->setText(QApplication::translate("FileFilterDlg", "File List", 0));
        label->setText(QApplication::translate("FileFilterDlg", "Root Directory", 0));
        all_select_btn->setText(QApplication::translate("FileFilterDlg", "All", 0));
        clear_btn->setText(QApplication::translate("FileFilterDlg", "Clear", 0));
        reverse_btn->setText(QApplication::translate("FileFilterDlg", "Reverse", 0));
        root_dir_btn->setText(QApplication::translate("FileFilterDlg", "...", 0));
        QTableWidgetItem *___qtablewidgetitem = file_list->horizontalHeaderItem(1);
        ___qtablewidgetitem->setText(QApplication::translate("FileFilterDlg", "File Name", 0));
        ok_btn->setText(QApplication::translate("FileFilterDlg", "OK", 0));
        cancel_btn->setText(QApplication::translate("FileFilterDlg", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class FileFilterDlg: public Ui_FileFilterDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILEFILTERDLG_H
