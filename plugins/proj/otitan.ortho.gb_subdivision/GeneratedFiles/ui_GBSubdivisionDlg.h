/********************************************************************************
** Form generated from reading UI file 'GBSubdivisionDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GBSUBDIVISIONDLG_H
#define UI_GBSUBDIVISIONDLG_H

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
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_GBSubdivisionDlg
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *input_imgs_txt;
    QPushButton *input_btn;
    QLabel *label_2;
    QComboBox *cut_method_box;
    QLabel *scale_label;
    QComboBox *scale_box;
    QLabel *graph_sym_label;
    QLineEdit *graph_sym_txt;
    QCheckBox *use_graph_check;
    QLabel *label_12;
    QLabel *label_3;
    QLineEdit *output_path_txt;
    QPushButton *output_path_btn;
    QLabel *label_14;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *file_pre_txt;
    QLabel *label_15;
    QLineEdit *file_suf_txt;
    QLabel *label_4;
    QComboBox *out_format_box;
    QFrame *line;
    QLabel *label_5;
    QComboBox *expand_method_box;
    QLabel *label_6;
    QComboBox *resample_method_box;
    QLabel *label_7;
    QLineEdit *no_data_txt;
    QLabel *label_8;
    QLineEdit *expand_pixel_txt;
    QLabel *label_9;
    QHBoxLayout *horizontalLayout;
    QLabel *label_10;
    QLineEdit *x_res_txt;
    QLabel *label_11;
    QLineEdit *y_res_txt;
    QCheckBox *keep_out_check;
    QCheckBox *out_check;
    QCheckBox *build_overview_check;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *ok_btn;
    QSpacerItem *horizontalSpacer;
    QPushButton *cancel_btn;
    QSpacerItem *horizontalSpacer_3;
    QTableWidget *graph_tab;

    void setupUi(QDialog *GBSubdivisionDlg)
    {
        if (GBSubdivisionDlg->objectName().isEmpty())
            GBSubdivisionDlg->setObjectName(QStringLiteral("GBSubdivisionDlg"));
        GBSubdivisionDlg->resize(550, 661);
        gridLayout = new QGridLayout(GBSubdivisionDlg);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(GBSubdivisionDlg);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        input_imgs_txt = new QLineEdit(GBSubdivisionDlg);
        input_imgs_txt->setObjectName(QStringLiteral("input_imgs_txt"));
        input_imgs_txt->setMinimumSize(QSize(0, 25));
        input_imgs_txt->setReadOnly(true);

        gridLayout->addWidget(input_imgs_txt, 0, 2, 1, 1);

        input_btn = new QPushButton(GBSubdivisionDlg);
        input_btn->setObjectName(QStringLiteral("input_btn"));
        input_btn->setMinimumSize(QSize(25, 25));
        input_btn->setMaximumSize(QSize(25, 25));

        gridLayout->addWidget(input_btn, 0, 3, 1, 1);

        label_2 = new QLabel(GBSubdivisionDlg);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        cut_method_box = new QComboBox(GBSubdivisionDlg);
        cut_method_box->setObjectName(QStringLiteral("cut_method_box"));
        cut_method_box->setMinimumSize(QSize(0, 25));

        gridLayout->addWidget(cut_method_box, 1, 2, 1, 1);

        scale_label = new QLabel(GBSubdivisionDlg);
        scale_label->setObjectName(QStringLiteral("scale_label"));

        gridLayout->addWidget(scale_label, 2, 0, 1, 1);

        scale_box = new QComboBox(GBSubdivisionDlg);
        scale_box->setObjectName(QStringLiteral("scale_box"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(scale_box->sizePolicy().hasHeightForWidth());
        scale_box->setSizePolicy(sizePolicy);
        scale_box->setMinimumSize(QSize(0, 25));
        scale_box->setMaximumSize(QSize(16777215, 25));

        gridLayout->addWidget(scale_box, 2, 2, 1, 1);

        graph_sym_label = new QLabel(GBSubdivisionDlg);
        graph_sym_label->setObjectName(QStringLiteral("graph_sym_label"));

        gridLayout->addWidget(graph_sym_label, 3, 0, 1, 1);

        graph_sym_txt = new QLineEdit(GBSubdivisionDlg);
        graph_sym_txt->setObjectName(QStringLiteral("graph_sym_txt"));
        sizePolicy.setHeightForWidth(graph_sym_txt->sizePolicy().hasHeightForWidth());
        graph_sym_txt->setSizePolicy(sizePolicy);
        graph_sym_txt->setMinimumSize(QSize(0, 25));
        graph_sym_txt->setMaximumSize(QSize(16777215, 25));

        gridLayout->addWidget(graph_sym_txt, 3, 2, 1, 1);

        use_graph_check = new QCheckBox(GBSubdivisionDlg);
        use_graph_check->setObjectName(QStringLiteral("use_graph_check"));
        use_graph_check->setChecked(true);

        gridLayout->addWidget(use_graph_check, 4, 2, 1, 1);

        label_12 = new QLabel(GBSubdivisionDlg);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout->addWidget(label_12, 5, 0, 1, 1);

        label_3 = new QLabel(GBSubdivisionDlg);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 6, 0, 1, 1);

        output_path_txt = new QLineEdit(GBSubdivisionDlg);
        output_path_txt->setObjectName(QStringLiteral("output_path_txt"));
        output_path_txt->setMinimumSize(QSize(0, 25));
        output_path_txt->setReadOnly(true);

        gridLayout->addWidget(output_path_txt, 6, 2, 1, 1);

        output_path_btn = new QPushButton(GBSubdivisionDlg);
        output_path_btn->setObjectName(QStringLiteral("output_path_btn"));
        output_path_btn->setMinimumSize(QSize(25, 25));
        output_path_btn->setMaximumSize(QSize(25, 25));

        gridLayout->addWidget(output_path_btn, 6, 3, 1, 1);

        label_14 = new QLabel(GBSubdivisionDlg);
        label_14->setObjectName(QStringLiteral("label_14"));

        gridLayout->addWidget(label_14, 7, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        file_pre_txt = new QLineEdit(GBSubdivisionDlg);
        file_pre_txt->setObjectName(QStringLiteral("file_pre_txt"));
        file_pre_txt->setMinimumSize(QSize(0, 25));

        horizontalLayout_3->addWidget(file_pre_txt);

        label_15 = new QLabel(GBSubdivisionDlg);
        label_15->setObjectName(QStringLiteral("label_15"));

        horizontalLayout_3->addWidget(label_15);

        file_suf_txt = new QLineEdit(GBSubdivisionDlg);
        file_suf_txt->setObjectName(QStringLiteral("file_suf_txt"));
        file_suf_txt->setMinimumSize(QSize(0, 25));

        horizontalLayout_3->addWidget(file_suf_txt);


        gridLayout->addLayout(horizontalLayout_3, 7, 2, 1, 1);

        label_4 = new QLabel(GBSubdivisionDlg);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 8, 0, 1, 1);

        out_format_box = new QComboBox(GBSubdivisionDlg);
        out_format_box->setObjectName(QStringLiteral("out_format_box"));
        out_format_box->setMinimumSize(QSize(0, 25));

        gridLayout->addWidget(out_format_box, 8, 2, 1, 1);

        line = new QFrame(GBSubdivisionDlg);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 9, 0, 1, 4);

        label_5 = new QLabel(GBSubdivisionDlg);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 10, 0, 1, 1);

        expand_method_box = new QComboBox(GBSubdivisionDlg);
        expand_method_box->setObjectName(QStringLiteral("expand_method_box"));
        expand_method_box->setMinimumSize(QSize(0, 25));

        gridLayout->addWidget(expand_method_box, 10, 2, 1, 1);

        label_6 = new QLabel(GBSubdivisionDlg);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 11, 0, 1, 1);

        resample_method_box = new QComboBox(GBSubdivisionDlg);
        resample_method_box->setObjectName(QStringLiteral("resample_method_box"));
        resample_method_box->setMinimumSize(QSize(0, 25));

        gridLayout->addWidget(resample_method_box, 11, 2, 1, 1);

        label_7 = new QLabel(GBSubdivisionDlg);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 12, 0, 1, 1);

        no_data_txt = new QLineEdit(GBSubdivisionDlg);
        no_data_txt->setObjectName(QStringLiteral("no_data_txt"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(no_data_txt->sizePolicy().hasHeightForWidth());
        no_data_txt->setSizePolicy(sizePolicy1);
        no_data_txt->setMinimumSize(QSize(0, 25));

        gridLayout->addWidget(no_data_txt, 12, 2, 1, 1);

        label_8 = new QLabel(GBSubdivisionDlg);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout->addWidget(label_8, 13, 0, 1, 1);

        expand_pixel_txt = new QLineEdit(GBSubdivisionDlg);
        expand_pixel_txt->setObjectName(QStringLiteral("expand_pixel_txt"));
        sizePolicy1.setHeightForWidth(expand_pixel_txt->sizePolicy().hasHeightForWidth());
        expand_pixel_txt->setSizePolicy(sizePolicy1);
        expand_pixel_txt->setMinimumSize(QSize(0, 25));

        gridLayout->addWidget(expand_pixel_txt, 13, 2, 1, 1);

        label_9 = new QLabel(GBSubdivisionDlg);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout->addWidget(label_9, 14, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_10 = new QLabel(GBSubdivisionDlg);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout->addWidget(label_10);

        x_res_txt = new QLineEdit(GBSubdivisionDlg);
        x_res_txt->setObjectName(QStringLiteral("x_res_txt"));
        x_res_txt->setMinimumSize(QSize(0, 25));

        horizontalLayout->addWidget(x_res_txt);

        label_11 = new QLabel(GBSubdivisionDlg);
        label_11->setObjectName(QStringLiteral("label_11"));

        horizontalLayout->addWidget(label_11);

        y_res_txt = new QLineEdit(GBSubdivisionDlg);
        y_res_txt->setObjectName(QStringLiteral("y_res_txt"));
        y_res_txt->setMinimumSize(QSize(0, 25));

        horizontalLayout->addWidget(y_res_txt);


        gridLayout->addLayout(horizontalLayout, 14, 2, 1, 1);

        keep_out_check = new QCheckBox(GBSubdivisionDlg);
        keep_out_check->setObjectName(QStringLiteral("keep_out_check"));

        gridLayout->addWidget(keep_out_check, 15, 2, 1, 1);

        out_check = new QCheckBox(GBSubdivisionDlg);
        out_check->setObjectName(QStringLiteral("out_check"));

        gridLayout->addWidget(out_check, 16, 2, 1, 1);

        build_overview_check = new QCheckBox(GBSubdivisionDlg);
        build_overview_check->setObjectName(QStringLiteral("build_overview_check"));

        gridLayout->addWidget(build_overview_check, 17, 2, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        ok_btn = new QPushButton(GBSubdivisionDlg);
        ok_btn->setObjectName(QStringLiteral("ok_btn"));

        horizontalLayout_2->addWidget(ok_btn);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        cancel_btn = new QPushButton(GBSubdivisionDlg);
        cancel_btn->setObjectName(QStringLiteral("cancel_btn"));

        horizontalLayout_2->addWidget(cancel_btn);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        gridLayout->addLayout(horizontalLayout_2, 18, 0, 1, 4);

        graph_tab = new QTableWidget(GBSubdivisionDlg);
        if (graph_tab->columnCount() < 3)
            graph_tab->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        graph_tab->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        graph_tab->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        graph_tab->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        graph_tab->setObjectName(QStringLiteral("graph_tab"));
        sizePolicy.setHeightForWidth(graph_tab->sizePolicy().hasHeightForWidth());
        graph_tab->setSizePolicy(sizePolicy);
        graph_tab->setMinimumSize(QSize(0, 100));
        graph_tab->setEditTriggers(QAbstractItemView::NoEditTriggers);
        graph_tab->setSelectionBehavior(QAbstractItemView::SelectRows);
        graph_tab->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        graph_tab->verticalHeader()->setVisible(false);

        gridLayout->addWidget(graph_tab, 5, 2, 1, 1);


        retranslateUi(GBSubdivisionDlg);

        QMetaObject::connectSlotsByName(GBSubdivisionDlg);
    } // setupUi

    void retranslateUi(QDialog *GBSubdivisionDlg)
    {
        GBSubdivisionDlg->setWindowTitle(QApplication::translate("GBSubdivisionDlg", "GBSubdivisionDlg", 0));
        label->setText(QApplication::translate("GBSubdivisionDlg", "Input iImages", 0));
        input_btn->setText(QApplication::translate("GBSubdivisionDlg", "...", 0));
        label_2->setText(QApplication::translate("GBSubdivisionDlg", "Cut method", 0));
        cut_method_box->clear();
        cut_method_box->insertItems(0, QStringList()
         << QApplication::translate("GBSubdivisionDlg", "Standard frame cutting", 0)
         << QApplication::translate("GBSubdivisionDlg", "Graph symbol cutting", 0)
        );
        scale_label->setText(QApplication::translate("GBSubdivisionDlg", "Scale", 0));
        scale_box->clear();
        scale_box->insertItems(0, QStringList()
         << QApplication::translate("GBSubdivisionDlg", "1:500", 0)
         << QApplication::translate("GBSubdivisionDlg", "1:1000", 0)
         << QApplication::translate("GBSubdivisionDlg", "1:2000", 0)
         << QApplication::translate("GBSubdivisionDlg", "1:5000", 0)
         << QApplication::translate("GBSubdivisionDlg", "1:10000", 0)
         << QApplication::translate("GBSubdivisionDlg", "1:25000", 0)
         << QApplication::translate("GBSubdivisionDlg", "1:50000", 0)
         << QApplication::translate("GBSubdivisionDlg", "1:100000", 0)
         << QApplication::translate("GBSubdivisionDlg", "1:250000", 0)
         << QApplication::translate("GBSubdivisionDlg", "1:500000", 0)
         << QApplication::translate("GBSubdivisionDlg", "1:1000000", 0)
        );
        graph_sym_label->setText(QApplication::translate("GBSubdivisionDlg", "Graph Symbol", 0));
        use_graph_check->setText(QApplication::translate("GBSubdivisionDlg", "Using all graph symbol", 0));
        label_12->setText(QApplication::translate("GBSubdivisionDlg", "Graph Symbol", 0));
        label_3->setText(QApplication::translate("GBSubdivisionDlg", "Output path", 0));
        output_path_btn->setText(QApplication::translate("GBSubdivisionDlg", "...", 0));
        label_14->setText(QApplication::translate("GBSubdivisionDlg", "Filename prefix", 0));
        label_15->setText(QApplication::translate("GBSubdivisionDlg", "Filename suffix", 0));
        label_4->setText(QApplication::translate("GBSubdivisionDlg", "Output format", 0));
        label_5->setText(QApplication::translate("GBSubdivisionDlg", "Expansion method", 0));
        expand_method_box->clear();
        expand_method_box->insertItems(0, QStringList()
         << QApplication::translate("GBSubdivisionDlg", "Rectangle expansion", 0)
         << QApplication::translate("GBSubdivisionDlg", "Polygon expansion", 0)
        );
        label_6->setText(QApplication::translate("GBSubdivisionDlg", "Resampling method", 0));
        resample_method_box->clear();
        resample_method_box->insertItems(0, QStringList()
         << QApplication::translate("GBSubdivisionDlg", "NEAREST", 0)
         << QApplication::translate("GBSubdivisionDlg", "BILINEAR", 0)
         << QApplication::translate("GBSubdivisionDlg", "CUBIC", 0)
         << QApplication::translate("GBSubdivisionDlg", "GAUSS", 0)
        );
        label_7->setText(QApplication::translate("GBSubdivisionDlg", "No data value", 0));
        label_8->setText(QApplication::translate("GBSubdivisionDlg", "Expansion pixel", 0));
        label_9->setText(QApplication::translate("GBSubdivisionDlg", "Output resolution", 0));
        label_10->setText(QApplication::translate("GBSubdivisionDlg", "x:", 0));
        label_11->setText(QApplication::translate("GBSubdivisionDlg", "y:", 0));
        keep_out_check->setText(QApplication::translate("GBSubdivisionDlg", "Keep out of the image", 0));
        out_check->setText(QApplication::translate("GBSubdivisionDlg", "Output cutting edge", 0));
        build_overview_check->setText(QApplication::translate("GBSubdivisionDlg", "Building overview", 0));
        ok_btn->setText(QApplication::translate("GBSubdivisionDlg", "OK", 0));
        cancel_btn->setText(QApplication::translate("GBSubdivisionDlg", "Cancel", 0));
        QTableWidgetItem *___qtablewidgetitem = graph_tab->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("GBSubdivisionDlg", "Sign", 0));
        QTableWidgetItem *___qtablewidgetitem1 = graph_tab->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("GBSubdivisionDlg", "Number", 0));
        QTableWidgetItem *___qtablewidgetitem2 = graph_tab->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("GBSubdivisionDlg", "Symbol", 0));
    } // retranslateUi

};

namespace Ui {
    class GBSubdivisionDlg: public Ui_GBSubdivisionDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GBSUBDIVISIONDLG_H
