/********************************************************************************
** Form generated from reading UI file 'FileCompressDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILECOMPRESSDLG_H
#define UI_FILECOMPRESSDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
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

class Ui_FileCompressDlg
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QRadioButton *file_list_radio;
    QRadioButton *dir_list_radio;
    QLabel *label_2;
    QLabel *sub_file_label;
    QGridLayout *gridLayout_3;
    QToolButton *sub_file_del_btn;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QCheckBox *ignore_check;
    QGridLayout *gridLayout_4;
    QToolButton *add_file_btn;
    QToolButton *file_filter_btn;
    QToolButton *file_del_btn;
    QListWidget *file_list;
    QListWidget *sub_file_list;
    QLineEdit *output_path;
    QLineEdit *output_filename;
    QFrame *frame;
    QGridLayout *gridLayout_2;
    QRadioButton *tar_radio;
    QRadioButton *tar_gz_btn;
    QRadioButton *tar_bz_btn;
    QRadioButton *zip_radio;
    QPushButton *output_path_btn;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *ok_btn;
    QSpacerItem *horizontalSpacer;
    QPushButton *cancel_btn;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout;
    QCheckBox *contain_sub_check;
    QCheckBox *contain_mul_check;

    void setupUi(QDialog *FileCompressDlg)
    {
        if (FileCompressDlg->objectName().isEmpty())
            FileCompressDlg->setObjectName(QStringLiteral("FileCompressDlg"));
        FileCompressDlg->resize(573, 535);
        gridLayout = new QGridLayout(FileCompressDlg);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(FileCompressDlg);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        file_list_radio = new QRadioButton(FileCompressDlg);
        file_list_radio->setObjectName(QStringLiteral("file_list_radio"));

        gridLayout->addWidget(file_list_radio, 0, 1, 1, 1);

        dir_list_radio = new QRadioButton(FileCompressDlg);
        dir_list_radio->setObjectName(QStringLiteral("dir_list_radio"));

        gridLayout->addWidget(dir_list_radio, 0, 2, 1, 1);

        label_2 = new QLabel(FileCompressDlg);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        sub_file_label = new QLabel(FileCompressDlg);
        sub_file_label->setObjectName(QStringLiteral("sub_file_label"));
        sizePolicy.setHeightForWidth(sub_file_label->sizePolicy().hasHeightForWidth());
        sub_file_label->setSizePolicy(sizePolicy);
        sub_file_label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        gridLayout->addWidget(sub_file_label, 3, 0, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        sub_file_del_btn = new QToolButton(FileCompressDlg);
        sub_file_del_btn->setObjectName(QStringLiteral("sub_file_del_btn"));
        sub_file_del_btn->setMinimumSize(QSize(25, 25));
        sub_file_del_btn->setMaximumSize(QSize(25, 25));
        QIcon icon;
        icon.addFile(QStringLiteral(":/file/remove_image.png"), QSize(), QIcon::Normal, QIcon::Off);
        sub_file_del_btn->setIcon(icon);

        gridLayout_3->addWidget(sub_file_del_btn, 0, 0, 1, 1);


        gridLayout->addLayout(gridLayout_3, 3, 4, 1, 1);

        label_4 = new QLabel(FileCompressDlg);
        label_4->setObjectName(QStringLiteral("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label_4, 4, 0, 1, 1);

        label_5 = new QLabel(FileCompressDlg);
        label_5->setObjectName(QStringLiteral("label_5"));
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label_5, 5, 0, 1, 1);

        label_6 = new QLabel(FileCompressDlg);
        label_6->setObjectName(QStringLiteral("label_6"));
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label_6, 6, 0, 1, 1);

        label_7 = new QLabel(FileCompressDlg);
        label_7->setObjectName(QStringLiteral("label_7"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(label_7, 7, 1, 1, 2);

        ignore_check = new QCheckBox(FileCompressDlg);
        ignore_check->setObjectName(QStringLiteral("ignore_check"));

        gridLayout->addWidget(ignore_check, 8, 1, 1, 2);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        add_file_btn = new QToolButton(FileCompressDlg);
        add_file_btn->setObjectName(QStringLiteral("add_file_btn"));
        add_file_btn->setMinimumSize(QSize(25, 25));
        add_file_btn->setMaximumSize(QSize(25, 25));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/file/add_image.png"), QSize(), QIcon::Normal, QIcon::Off);
        add_file_btn->setIcon(icon1);

        gridLayout_4->addWidget(add_file_btn, 0, 0, 1, 1);

        file_filter_btn = new QToolButton(FileCompressDlg);
        file_filter_btn->setObjectName(QStringLiteral("file_filter_btn"));
        file_filter_btn->setMinimumSize(QSize(25, 25));
        file_filter_btn->setMaximumSize(QSize(25, 25));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/file/find_image.png"), QSize(), QIcon::Normal, QIcon::Off);
        file_filter_btn->setIcon(icon2);

        gridLayout_4->addWidget(file_filter_btn, 1, 0, 1, 1);

        file_del_btn = new QToolButton(FileCompressDlg);
        file_del_btn->setObjectName(QStringLiteral("file_del_btn"));
        file_del_btn->setMinimumSize(QSize(25, 25));
        file_del_btn->setMaximumSize(QSize(25, 25));
        file_del_btn->setIcon(icon);

        gridLayout_4->addWidget(file_del_btn, 2, 0, 1, 1);


        gridLayout->addLayout(gridLayout_4, 1, 4, 1, 1);

        file_list = new QListWidget(FileCompressDlg);
        file_list->setObjectName(QStringLiteral("file_list"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(file_list->sizePolicy().hasHeightForWidth());
        file_list->setSizePolicy(sizePolicy2);
        file_list->setSelectionMode(QAbstractItemView::ExtendedSelection);

        gridLayout->addWidget(file_list, 1, 1, 1, 2);

        sub_file_list = new QListWidget(FileCompressDlg);
        sub_file_list->setObjectName(QStringLiteral("sub_file_list"));
        sizePolicy2.setHeightForWidth(sub_file_list->sizePolicy().hasHeightForWidth());
        sub_file_list->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(sub_file_list, 3, 1, 1, 2);

        output_path = new QLineEdit(FileCompressDlg);
        output_path->setObjectName(QStringLiteral("output_path"));
        sizePolicy1.setHeightForWidth(output_path->sizePolicy().hasHeightForWidth());
        output_path->setSizePolicy(sizePolicy1);
        output_path->setMinimumSize(QSize(0, 25));
        output_path->setReadOnly(true);

        gridLayout->addWidget(output_path, 4, 1, 1, 2);

        output_filename = new QLineEdit(FileCompressDlg);
        output_filename->setObjectName(QStringLiteral("output_filename"));
        sizePolicy1.setHeightForWidth(output_filename->sizePolicy().hasHeightForWidth());
        output_filename->setSizePolicy(sizePolicy1);
        output_filename->setMinimumSize(QSize(0, 25));

        gridLayout->addWidget(output_filename, 5, 1, 1, 2);

        frame = new QFrame(FileCompressDlg);
        frame->setObjectName(QStringLiteral("frame"));
        sizePolicy1.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy1);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Sunken);
        gridLayout_2 = new QGridLayout(frame);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        tar_radio = new QRadioButton(frame);
        tar_radio->setObjectName(QStringLiteral("tar_radio"));

        gridLayout_2->addWidget(tar_radio, 0, 0, 1, 1);

        tar_gz_btn = new QRadioButton(frame);
        tar_gz_btn->setObjectName(QStringLiteral("tar_gz_btn"));

        gridLayout_2->addWidget(tar_gz_btn, 0, 1, 1, 1);

        tar_bz_btn = new QRadioButton(frame);
        tar_bz_btn->setObjectName(QStringLiteral("tar_bz_btn"));

        gridLayout_2->addWidget(tar_bz_btn, 0, 2, 1, 1);

        zip_radio = new QRadioButton(frame);
        zip_radio->setObjectName(QStringLiteral("zip_radio"));

        gridLayout_2->addWidget(zip_radio, 0, 3, 1, 1);


        gridLayout->addWidget(frame, 6, 1, 1, 2);

        output_path_btn = new QPushButton(FileCompressDlg);
        output_path_btn->setObjectName(QStringLiteral("output_path_btn"));
        output_path_btn->setMinimumSize(QSize(25, 25));
        output_path_btn->setMaximumSize(QSize(25, 25));

        gridLayout->addWidget(output_path_btn, 4, 4, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        ok_btn = new QPushButton(FileCompressDlg);
        ok_btn->setObjectName(QStringLiteral("ok_btn"));

        horizontalLayout_2->addWidget(ok_btn);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        cancel_btn = new QPushButton(FileCompressDlg);
        cancel_btn->setObjectName(QStringLiteral("cancel_btn"));

        horizontalLayout_2->addWidget(cancel_btn);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        gridLayout->addLayout(horizontalLayout_2, 9, 0, 1, 3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        contain_sub_check = new QCheckBox(FileCompressDlg);
        contain_sub_check->setObjectName(QStringLiteral("contain_sub_check"));

        horizontalLayout->addWidget(contain_sub_check);

        contain_mul_check = new QCheckBox(FileCompressDlg);
        contain_mul_check->setObjectName(QStringLiteral("contain_mul_check"));

        horizontalLayout->addWidget(contain_mul_check);


        gridLayout->addLayout(horizontalLayout, 2, 1, 1, 2);


        retranslateUi(FileCompressDlg);

        QMetaObject::connectSlotsByName(FileCompressDlg);
    } // setupUi

    void retranslateUi(QDialog *FileCompressDlg)
    {
        FileCompressDlg->setWindowTitle(QApplication::translate("FileCompressDlg", "FileCompressDlg", 0));
        label->setText(QApplication::translate("FileCompressDlg", "Output type", 0));
        file_list_radio->setText(QApplication::translate("FileCompressDlg", "File list", 0));
        dir_list_radio->setText(QApplication::translate("FileCompressDlg", "Directory list", 0));
        label_2->setText(QApplication::translate("FileCompressDlg", "File list", 0));
        sub_file_label->setText(QApplication::translate("FileCompressDlg", "Subsidiary files", 0));
        sub_file_del_btn->setText(QApplication::translate("FileCompressDlg", "...", 0));
        label_4->setText(QApplication::translate("FileCompressDlg", "Output path", 0));
        label_5->setText(QApplication::translate("FileCompressDlg", "Output filename", 0));
        label_6->setText(QApplication::translate("FileCompressDlg", "Output format", 0));
        label_7->setText(QApplication::translate("FileCompressDlg", "Note: local implementation mode only supports zip format", 0));
        ignore_check->setText(QApplication::translate("FileCompressDlg", "Ignore warnings and errors in the process of compression", 0));
        add_file_btn->setText(QString());
        file_filter_btn->setText(QString());
        file_del_btn->setText(QString());
        tar_radio->setText(QApplication::translate("FileCompressDlg", ".tar", 0));
        tar_gz_btn->setText(QApplication::translate("FileCompressDlg", ".tar.gz", 0));
        tar_bz_btn->setText(QApplication::translate("FileCompressDlg", ".tar.bz2", 0));
        zip_radio->setText(QApplication::translate("FileCompressDlg", ".zip", 0));
        output_path_btn->setText(QApplication::translate("FileCompressDlg", "...", 0));
        ok_btn->setText(QApplication::translate("FileCompressDlg", "OK", 0));
        cancel_btn->setText(QApplication::translate("FileCompressDlg", "Cancel", 0));
#ifndef QT_NO_TOOLTIP
        contain_sub_check->setToolTip(QApplication::translate("FileCompressDlg", "The same file name prefix for each file name in the file list belongs to the file of the file.", 0));
#endif // QT_NO_TOOLTIP
        contain_sub_check->setText(QApplication::translate("FileCompressDlg", "Contains subsidiary files", 0));
#ifndef QT_NO_TOOLTIP
        contain_mul_check->setToolTip(QApplication::translate("FileCompressDlg", "Each file and the subsidiary file, or each directory, respectively, to generate a compressed package", 0));
#endif // QT_NO_TOOLTIP
        contain_mul_check->setText(QApplication::translate("FileCompressDlg", "Generates multiple compress packages", 0));
    } // retranslateUi

};

namespace Ui {
    class FileCompressDlg: public Ui_FileCompressDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILECOMPRESSDLG_H
