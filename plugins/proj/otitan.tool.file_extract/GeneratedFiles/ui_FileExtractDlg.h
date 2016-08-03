/********************************************************************************
** Form generated from reading UI file 'FileExtractDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILEEXTRACTDLG_H
#define UI_FILEEXTRACTDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_FileExtractDlg
{
public:
    QGridLayout *gridLayout;
    QRadioButton *extract_diff_radio;
    QListWidget *file_list;
    QPushButton *output_path_btn;
    QGridLayout *gridLayout_2;
    QToolButton *add_file_btn;
    QToolButton *del_file_btn;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *ok_btn;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *cancel_btn;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_2;
    QRadioButton *extract_same_radio;
    QCheckBox *ignore_err_check;
    QLabel *label;
    QLabel *label_3;
    QLineEdit *output_path_txt;

    void setupUi(QDialog *FileExtractDlg)
    {
        if (FileExtractDlg->objectName().isEmpty())
            FileExtractDlg->setObjectName(QStringLiteral("FileExtractDlg"));
        FileExtractDlg->resize(667, 310);
        gridLayout = new QGridLayout(FileExtractDlg);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        extract_diff_radio = new QRadioButton(FileExtractDlg);
        extract_diff_radio->setObjectName(QStringLiteral("extract_diff_radio"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(extract_diff_radio->sizePolicy().hasHeightForWidth());
        extract_diff_radio->setSizePolicy(sizePolicy);

        gridLayout->addWidget(extract_diff_radio, 0, 2, 1, 1);

        file_list = new QListWidget(FileExtractDlg);
        file_list->setObjectName(QStringLiteral("file_list"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(file_list->sizePolicy().hasHeightForWidth());
        file_list->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(file_list, 1, 1, 1, 2);

        output_path_btn = new QPushButton(FileExtractDlg);
        output_path_btn->setObjectName(QStringLiteral("output_path_btn"));
        output_path_btn->setMinimumSize(QSize(25, 25));
        output_path_btn->setMaximumSize(QSize(25, 25));

        gridLayout->addWidget(output_path_btn, 2, 3, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        add_file_btn = new QToolButton(FileExtractDlg);
        add_file_btn->setObjectName(QStringLiteral("add_file_btn"));
        add_file_btn->setMinimumSize(QSize(25, 25));
        add_file_btn->setMaximumSize(QSize(25, 25));
        QIcon icon;
        icon.addFile(QStringLiteral(":/file/add_image.png"), QSize(), QIcon::Normal, QIcon::Off);
        add_file_btn->setIcon(icon);

        gridLayout_2->addWidget(add_file_btn, 0, 0, 1, 1);

        del_file_btn = new QToolButton(FileExtractDlg);
        del_file_btn->setObjectName(QStringLiteral("del_file_btn"));
        del_file_btn->setMinimumSize(QSize(25, 25));
        del_file_btn->setMaximumSize(QSize(25, 25));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/file/remove_image.png"), QSize(), QIcon::Normal, QIcon::Off);
        del_file_btn->setIcon(icon1);

        gridLayout_2->addWidget(del_file_btn, 1, 0, 1, 1);


        gridLayout->addLayout(gridLayout_2, 1, 3, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        ok_btn = new QPushButton(FileExtractDlg);
        ok_btn->setObjectName(QStringLiteral("ok_btn"));

        horizontalLayout->addWidget(ok_btn);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        cancel_btn = new QPushButton(FileExtractDlg);
        cancel_btn->setObjectName(QStringLiteral("cancel_btn"));

        horizontalLayout->addWidget(cancel_btn);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        gridLayout->addLayout(horizontalLayout, 5, 0, 1, 4);

        label_2 = new QLabel(FileExtractDlg);
        label_2->setObjectName(QStringLiteral("label_2"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        extract_same_radio = new QRadioButton(FileExtractDlg);
        extract_same_radio->setObjectName(QStringLiteral("extract_same_radio"));
        sizePolicy.setHeightForWidth(extract_same_radio->sizePolicy().hasHeightForWidth());
        extract_same_radio->setSizePolicy(sizePolicy);
        extract_same_radio->setChecked(true);

        gridLayout->addWidget(extract_same_radio, 0, 1, 1, 1);

        ignore_err_check = new QCheckBox(FileExtractDlg);
        ignore_err_check->setObjectName(QStringLiteral("ignore_err_check"));

        gridLayout->addWidget(ignore_err_check, 4, 1, 1, 1);

        label = new QLabel(FileExtractDlg);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy2.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_3 = new QLabel(FileExtractDlg);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy2.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        output_path_txt = new QLineEdit(FileExtractDlg);
        output_path_txt->setObjectName(QStringLiteral("output_path_txt"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(output_path_txt->sizePolicy().hasHeightForWidth());
        output_path_txt->setSizePolicy(sizePolicy3);
        output_path_txt->setMinimumSize(QSize(0, 25));
        output_path_txt->setMaximumSize(QSize(16777215, 25));
        output_path_txt->setReadOnly(true);

        gridLayout->addWidget(output_path_txt, 2, 1, 1, 2);


        retranslateUi(FileExtractDlg);

        QMetaObject::connectSlotsByName(FileExtractDlg);
    } // setupUi

    void retranslateUi(QDialog *FileExtractDlg)
    {
        FileExtractDlg->setWindowTitle(QApplication::translate("FileExtractDlg", "FileExtractDlg", 0));
        extract_diff_radio->setText(QApplication::translate("FileExtractDlg", "Extract to an independent directory", 0));
        output_path_btn->setText(QApplication::translate("FileExtractDlg", "...", 0));
        add_file_btn->setText(QApplication::translate("FileExtractDlg", "...", 0));
        del_file_btn->setText(QApplication::translate("FileExtractDlg", "...", 0));
        ok_btn->setText(QApplication::translate("FileExtractDlg", "OK", 0));
        cancel_btn->setText(QApplication::translate("FileExtractDlg", "Cancel", 0));
        label_2->setText(QApplication::translate("FileExtractDlg", "File list", 0));
        extract_same_radio->setText(QApplication::translate("FileExtractDlg", "Extract to the same directory", 0));
        ignore_err_check->setText(QApplication::translate("FileExtractDlg", "Ignore warnings and errors during decompression", 0));
        label->setText(QApplication::translate("FileExtractDlg", "Options", 0));
        label_3->setText(QApplication::translate("FileExtractDlg", "Output path", 0));
    } // retranslateUi

};

namespace Ui {
    class FileExtractDlg: public Ui_FileExtractDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILEEXTRACTDLG_H
