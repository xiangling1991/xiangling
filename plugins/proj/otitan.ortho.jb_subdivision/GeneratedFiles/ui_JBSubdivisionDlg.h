/********************************************************************************
** Form generated from reading UI file 'JBSubdivisionDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JBSUBDIVISIONDLG_H
#define UI_JBSUBDIVISIONDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_JBSubdivisionDlg
{
public:
    QGridLayout *gridLayout;
    QCheckBox *build_overview_check;
    QCheckBox *keep_out_check;
    QCheckBox *out_check;
    QLabel *label_9;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *file_pre_txt;
    QLabel *label_15;
    QLineEdit *file_suf_txt;
    QLabel *label;
    QPushButton *input_btn;
    QLabel *label_2;
    QLabel *scale_label;
    QLabel *label_5;
    QComboBox *expand_method_box;
    QLabel *label_3;
    QPushButton *output_path_btn;
    QLabel *label_14;
    QComboBox *out_format_box;
    QLabel *label_4;
    QLabel *graph_sym_label;
    QLabel *label_7;
    QLineEdit *no_data_txt;
    QLabel *label_8;
    QLineEdit *expand_pixel_txt;
    QLabel *label_6;
    QComboBox *resample_method_box;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *ok_btn;
    QSpacerItem *horizontalSpacer;
    QPushButton *cancel_btn;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *input_imgs_txt;
    QLineEdit *output_path_txt;
    QComboBox *cut_method_box;
    QComboBox *scale_box;
    QLineEdit *graph_sym_txt;
    QHBoxLayout *horizontalLayout;
    QLabel *label_10;
    QLineEdit *x_res_txt;
    QLabel *label_11;
    QLineEdit *y_res_txt;
    QFrame *line;

    void setupUi(QDialog *JBSubdivisionDlg)
    {
        if (JBSubdivisionDlg->objectName().isEmpty())
            JBSubdivisionDlg->setObjectName(QStringLiteral("JBSubdivisionDlg"));
        JBSubdivisionDlg->resize(521, 591);
        gridLayout = new QGridLayout(JBSubdivisionDlg);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        build_overview_check = new QCheckBox(JBSubdivisionDlg);
        build_overview_check->setObjectName(QStringLiteral("build_overview_check"));

        gridLayout->addWidget(build_overview_check, 15, 3, 1, 1);

        keep_out_check = new QCheckBox(JBSubdivisionDlg);
        keep_out_check->setObjectName(QStringLiteral("keep_out_check"));

        gridLayout->addWidget(keep_out_check, 13, 3, 1, 1);

        out_check = new QCheckBox(JBSubdivisionDlg);
        out_check->setObjectName(QStringLiteral("out_check"));

        gridLayout->addWidget(out_check, 14, 3, 1, 1);

        label_9 = new QLabel(JBSubdivisionDlg);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout->addWidget(label_9, 12, 0, 1, 3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        file_pre_txt = new QLineEdit(JBSubdivisionDlg);
        file_pre_txt->setObjectName(QStringLiteral("file_pre_txt"));
        file_pre_txt->setMinimumSize(QSize(0, 25));

        horizontalLayout_3->addWidget(file_pre_txt);

        label_15 = new QLabel(JBSubdivisionDlg);
        label_15->setObjectName(QStringLiteral("label_15"));

        horizontalLayout_3->addWidget(label_15);

        file_suf_txt = new QLineEdit(JBSubdivisionDlg);
        file_suf_txt->setObjectName(QStringLiteral("file_suf_txt"));
        file_suf_txt->setMinimumSize(QSize(0, 25));

        horizontalLayout_3->addWidget(file_suf_txt);


        gridLayout->addLayout(horizontalLayout_3, 5, 3, 1, 1);

        label = new QLabel(JBSubdivisionDlg);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 2);

        input_btn = new QPushButton(JBSubdivisionDlg);
        input_btn->setObjectName(QStringLiteral("input_btn"));
        input_btn->setMinimumSize(QSize(25, 25));
        input_btn->setMaximumSize(QSize(25, 25));

        gridLayout->addWidget(input_btn, 0, 4, 1, 1);

        label_2 = new QLabel(JBSubdivisionDlg);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        scale_label = new QLabel(JBSubdivisionDlg);
        scale_label->setObjectName(QStringLiteral("scale_label"));

        gridLayout->addWidget(scale_label, 2, 0, 1, 1);

        label_5 = new QLabel(JBSubdivisionDlg);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 8, 0, 1, 2);

        expand_method_box = new QComboBox(JBSubdivisionDlg);
        expand_method_box->setObjectName(QStringLiteral("expand_method_box"));
        expand_method_box->setMinimumSize(QSize(0, 25));

        gridLayout->addWidget(expand_method_box, 8, 3, 1, 1);

        label_3 = new QLabel(JBSubdivisionDlg);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 4, 0, 1, 1);

        output_path_btn = new QPushButton(JBSubdivisionDlg);
        output_path_btn->setObjectName(QStringLiteral("output_path_btn"));
        output_path_btn->setMinimumSize(QSize(25, 25));
        output_path_btn->setMaximumSize(QSize(25, 25));

        gridLayout->addWidget(output_path_btn, 4, 4, 1, 1);

        label_14 = new QLabel(JBSubdivisionDlg);
        label_14->setObjectName(QStringLiteral("label_14"));

        gridLayout->addWidget(label_14, 5, 0, 1, 2);

        out_format_box = new QComboBox(JBSubdivisionDlg);
        out_format_box->setObjectName(QStringLiteral("out_format_box"));
        out_format_box->setMinimumSize(QSize(0, 25));

        gridLayout->addWidget(out_format_box, 6, 3, 1, 1);

        label_4 = new QLabel(JBSubdivisionDlg);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 6, 0, 1, 2);

        graph_sym_label = new QLabel(JBSubdivisionDlg);
        graph_sym_label->setObjectName(QStringLiteral("graph_sym_label"));

        gridLayout->addWidget(graph_sym_label, 3, 0, 1, 1);

        label_7 = new QLabel(JBSubdivisionDlg);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 10, 0, 1, 2);

        no_data_txt = new QLineEdit(JBSubdivisionDlg);
        no_data_txt->setObjectName(QStringLiteral("no_data_txt"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(no_data_txt->sizePolicy().hasHeightForWidth());
        no_data_txt->setSizePolicy(sizePolicy);
        no_data_txt->setMinimumSize(QSize(0, 25));

        gridLayout->addWidget(no_data_txt, 10, 3, 1, 1);

        label_8 = new QLabel(JBSubdivisionDlg);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout->addWidget(label_8, 11, 0, 1, 2);

        expand_pixel_txt = new QLineEdit(JBSubdivisionDlg);
        expand_pixel_txt->setObjectName(QStringLiteral("expand_pixel_txt"));
        sizePolicy.setHeightForWidth(expand_pixel_txt->sizePolicy().hasHeightForWidth());
        expand_pixel_txt->setSizePolicy(sizePolicy);
        expand_pixel_txt->setMinimumSize(QSize(0, 25));

        gridLayout->addWidget(expand_pixel_txt, 11, 3, 1, 1);

        label_6 = new QLabel(JBSubdivisionDlg);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 9, 0, 1, 3);

        resample_method_box = new QComboBox(JBSubdivisionDlg);
        resample_method_box->setObjectName(QStringLiteral("resample_method_box"));
        resample_method_box->setMinimumSize(QSize(0, 25));

        gridLayout->addWidget(resample_method_box, 9, 3, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        ok_btn = new QPushButton(JBSubdivisionDlg);
        ok_btn->setObjectName(QStringLiteral("ok_btn"));

        horizontalLayout_2->addWidget(ok_btn);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        cancel_btn = new QPushButton(JBSubdivisionDlg);
        cancel_btn->setObjectName(QStringLiteral("cancel_btn"));

        horizontalLayout_2->addWidget(cancel_btn);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        gridLayout->addLayout(horizontalLayout_2, 16, 0, 1, 5);

        input_imgs_txt = new QLineEdit(JBSubdivisionDlg);
        input_imgs_txt->setObjectName(QStringLiteral("input_imgs_txt"));
        input_imgs_txt->setMinimumSize(QSize(0, 25));
        input_imgs_txt->setReadOnly(true);

        gridLayout->addWidget(input_imgs_txt, 0, 3, 1, 1);

        output_path_txt = new QLineEdit(JBSubdivisionDlg);
        output_path_txt->setObjectName(QStringLiteral("output_path_txt"));
        output_path_txt->setMinimumSize(QSize(0, 25));
        output_path_txt->setReadOnly(true);

        gridLayout->addWidget(output_path_txt, 4, 3, 1, 1);

        cut_method_box = new QComboBox(JBSubdivisionDlg);
        cut_method_box->setObjectName(QStringLiteral("cut_method_box"));
        cut_method_box->setMinimumSize(QSize(0, 25));

        gridLayout->addWidget(cut_method_box, 1, 3, 1, 1);

        scale_box = new QComboBox(JBSubdivisionDlg);
        scale_box->setObjectName(QStringLiteral("scale_box"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(scale_box->sizePolicy().hasHeightForWidth());
        scale_box->setSizePolicy(sizePolicy1);
        scale_box->setMinimumSize(QSize(0, 25));
        scale_box->setMaximumSize(QSize(16777215, 25));

        gridLayout->addWidget(scale_box, 2, 3, 1, 1);

        graph_sym_txt = new QLineEdit(JBSubdivisionDlg);
        graph_sym_txt->setObjectName(QStringLiteral("graph_sym_txt"));
        sizePolicy1.setHeightForWidth(graph_sym_txt->sizePolicy().hasHeightForWidth());
        graph_sym_txt->setSizePolicy(sizePolicy1);
        graph_sym_txt->setMinimumSize(QSize(0, 25));
        graph_sym_txt->setMaximumSize(QSize(16777215, 25));

        gridLayout->addWidget(graph_sym_txt, 3, 3, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_10 = new QLabel(JBSubdivisionDlg);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout->addWidget(label_10);

        x_res_txt = new QLineEdit(JBSubdivisionDlg);
        x_res_txt->setObjectName(QStringLiteral("x_res_txt"));
        x_res_txt->setMinimumSize(QSize(0, 25));

        horizontalLayout->addWidget(x_res_txt);

        label_11 = new QLabel(JBSubdivisionDlg);
        label_11->setObjectName(QStringLiteral("label_11"));

        horizontalLayout->addWidget(label_11);

        y_res_txt = new QLineEdit(JBSubdivisionDlg);
        y_res_txt->setObjectName(QStringLiteral("y_res_txt"));
        y_res_txt->setMinimumSize(QSize(0, 25));

        horizontalLayout->addWidget(y_res_txt);


        gridLayout->addLayout(horizontalLayout, 12, 3, 1, 1);

        line = new QFrame(JBSubdivisionDlg);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 7, 0, 1, 5);


        retranslateUi(JBSubdivisionDlg);

        QMetaObject::connectSlotsByName(JBSubdivisionDlg);
    } // setupUi

    void retranslateUi(QDialog *JBSubdivisionDlg)
    {
        JBSubdivisionDlg->setWindowTitle(QApplication::translate("JBSubdivisionDlg", "JBSubdivisionDlg", 0));
        build_overview_check->setText(QApplication::translate("JBSubdivisionDlg", "Building overview", 0));
        keep_out_check->setText(QApplication::translate("JBSubdivisionDlg", "Keep out of the image", 0));
        out_check->setText(QApplication::translate("JBSubdivisionDlg", "Output cutting edge", 0));
        label_9->setText(QApplication::translate("JBSubdivisionDlg", "Output resolution", 0));
        label_15->setText(QApplication::translate("JBSubdivisionDlg", "Filename suffix", 0));
        label->setText(QApplication::translate("JBSubdivisionDlg", "Input iImages", 0));
        input_btn->setText(QApplication::translate("JBSubdivisionDlg", "...", 0));
        label_2->setText(QApplication::translate("JBSubdivisionDlg", "Cut method", 0));
        scale_label->setText(QApplication::translate("JBSubdivisionDlg", "Scale", 0));
        label_5->setText(QApplication::translate("JBSubdivisionDlg", "Expansion method", 0));
        expand_method_box->clear();
        expand_method_box->insertItems(0, QStringList()
         << QApplication::translate("JBSubdivisionDlg", "Rectangle expansion", 0)
         << QApplication::translate("JBSubdivisionDlg", "Polygon expansion", 0)
        );
        label_3->setText(QApplication::translate("JBSubdivisionDlg", "Output path", 0));
        output_path_btn->setText(QApplication::translate("JBSubdivisionDlg", "...", 0));
        label_14->setText(QApplication::translate("JBSubdivisionDlg", "Filename prefix", 0));
        label_4->setText(QApplication::translate("JBSubdivisionDlg", "Output format", 0));
        graph_sym_label->setText(QApplication::translate("JBSubdivisionDlg", "Graph Symbol", 0));
        label_7->setText(QApplication::translate("JBSubdivisionDlg", "No data value", 0));
        label_8->setText(QApplication::translate("JBSubdivisionDlg", "Expansion pixel", 0));
        label_6->setText(QApplication::translate("JBSubdivisionDlg", "Resampling method", 0));
        resample_method_box->clear();
        resample_method_box->insertItems(0, QStringList()
         << QApplication::translate("JBSubdivisionDlg", "NEAREST", 0)
         << QApplication::translate("JBSubdivisionDlg", "BILINEAR", 0)
         << QApplication::translate("JBSubdivisionDlg", "CUBIC", 0)
         << QApplication::translate("JBSubdivisionDlg", "GAUSS", 0)
        );
        ok_btn->setText(QApplication::translate("JBSubdivisionDlg", "OK", 0));
        cancel_btn->setText(QApplication::translate("JBSubdivisionDlg", "Cancel", 0));
        cut_method_box->clear();
        cut_method_box->insertItems(0, QStringList()
         << QApplication::translate("JBSubdivisionDlg", "Standard frame cutting", 0)
         << QApplication::translate("JBSubdivisionDlg", "Graph symbol cutting", 0)
        );
        scale_box->clear();
        scale_box->insertItems(0, QStringList()
         << QApplication::translate("JBSubdivisionDlg", "1:10000", 0)
         << QApplication::translate("JBSubdivisionDlg", "1:25000", 0)
         << QApplication::translate("JBSubdivisionDlg", "1:50000", 0)
         << QApplication::translate("JBSubdivisionDlg", "1:100000", 0)
         << QApplication::translate("JBSubdivisionDlg", "1:250000", 0)
         << QApplication::translate("JBSubdivisionDlg", "1:500000", 0)
         << QApplication::translate("JBSubdivisionDlg", "1:1000000", 0)
        );
        label_10->setText(QApplication::translate("JBSubdivisionDlg", "x:", 0));
        label_11->setText(QApplication::translate("JBSubdivisionDlg", "y:", 0));
    } // retranslateUi

};

namespace Ui {
    class JBSubdivisionDlg: public Ui_JBSubdivisionDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JBSUBDIVISIONDLG_H
