/********************************************************************************
** Form generated from reading UI file 'frmmain.ui'
**
** Created: Tue Nov 27 22:10:26 2012
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMMAIN_H
#define UI_FRMMAIN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_frmmain
{
public:
    QAction *action_exit;
    QAction *action_add_blog;
    QAction *action_delete_blog;
    QAction *action_about;
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *txt_blogname;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QTextEdit *txt_postcontent;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QTextEdit *txt_categories;
    QLabel *label_3;
    QTextEdit *txt_tags;
    QPushButton *btn_post;
    QMenuBar *menubar;
    QMenu *menu_File;
    QMenu *menu_Manager;
    QMenu *menu_help;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *frmmain)
    {
        if (frmmain->objectName().isEmpty())
            frmmain->setObjectName(QString::fromUtf8("frmmain"));
        frmmain->resize(582, 571);
        action_exit = new QAction(frmmain);
        action_exit->setObjectName(QString::fromUtf8("action_exit"));
        action_add_blog = new QAction(frmmain);
        action_add_blog->setObjectName(QString::fromUtf8("action_add_blog"));
        action_delete_blog = new QAction(frmmain);
        action_delete_blog->setObjectName(QString::fromUtf8("action_delete_blog"));
        action_about = new QAction(frmmain);
        action_about->setObjectName(QString::fromUtf8("action_about"));
        centralwidget = new QWidget(frmmain);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 0, 561, 27));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        txt_blogname = new QLineEdit(layoutWidget);
        txt_blogname->setObjectName(QString::fromUtf8("txt_blogname"));

        horizontalLayout->addWidget(txt_blogname);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(9, 40, 561, 471));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        txt_postcontent = new QTextEdit(layoutWidget1);
        txt_postcontent->setObjectName(QString::fromUtf8("txt_postcontent"));

        horizontalLayout_2->addWidget(txt_postcontent);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        txt_categories = new QTextEdit(layoutWidget1);
        txt_categories->setObjectName(QString::fromUtf8("txt_categories"));

        verticalLayout->addWidget(txt_categories);

        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);

        txt_tags = new QTextEdit(layoutWidget1);
        txt_tags->setObjectName(QString::fromUtf8("txt_tags"));

        verticalLayout->addWidget(txt_tags);

        btn_post = new QPushButton(layoutWidget1);
        btn_post->setObjectName(QString::fromUtf8("btn_post"));

        verticalLayout->addWidget(btn_post);


        horizontalLayout_2->addLayout(verticalLayout);

        frmmain->setCentralWidget(centralwidget);
        menubar = new QMenuBar(frmmain);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 582, 25));
        menu_File = new QMenu(menubar);
        menu_File->setObjectName(QString::fromUtf8("menu_File"));
        menu_Manager = new QMenu(menubar);
        menu_Manager->setObjectName(QString::fromUtf8("menu_Manager"));
        menu_help = new QMenu(menubar);
        menu_help->setObjectName(QString::fromUtf8("menu_help"));
        frmmain->setMenuBar(menubar);
        statusbar = new QStatusBar(frmmain);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        frmmain->setStatusBar(statusbar);
        toolBar = new QToolBar(frmmain);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        frmmain->addToolBar(Qt::TopToolBarArea, toolBar);
#ifndef QT_NO_SHORTCUT
        label->setBuddy(txt_blogname);
        label_2->setBuddy(txt_tags);
        label_3->setBuddy(txt_categories);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(txt_blogname, txt_categories);
        QWidget::setTabOrder(txt_categories, txt_tags);
        QWidget::setTabOrder(txt_tags, btn_post);
        QWidget::setTabOrder(btn_post, txt_postcontent);

        menubar->addAction(menu_File->menuAction());
        menubar->addAction(menu_Manager->menuAction());
        menubar->addAction(menu_help->menuAction());
        menu_File->addAction(action_exit);
        menu_Manager->addAction(action_add_blog);
        menu_Manager->addAction(action_delete_blog);
        menu_help->addAction(action_about);

        retranslateUi(frmmain);

        QMetaObject::connectSlotsByName(frmmain);
    } // setupUi

    void retranslateUi(QMainWindow *frmmain)
    {
        frmmain->setWindowTitle(QApplication::translate("frmmain", "Remote Blogs", 0, QApplication::UnicodeUTF8));
        action_exit->setText(QApplication::translate("frmmain", "&Exit", 0, QApplication::UnicodeUTF8));
        action_add_blog->setText(QApplication::translate("frmmain", "Add &Blog", 0, QApplication::UnicodeUTF8));
        action_delete_blog->setText(QApplication::translate("frmmain", "&Delete Blog", 0, QApplication::UnicodeUTF8));
        action_about->setText(QApplication::translate("frmmain", "&About", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("frmmain", "Blog Name:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("frmmain", "Categories:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("frmmain", "Tags:", 0, QApplication::UnicodeUTF8));
        btn_post->setText(QApplication::translate("frmmain", "Post", 0, QApplication::UnicodeUTF8));
        menu_File->setTitle(QApplication::translate("frmmain", "&File", 0, QApplication::UnicodeUTF8));
        menu_Manager->setTitle(QApplication::translate("frmmain", "&Manager", 0, QApplication::UnicodeUTF8));
        menu_help->setTitle(QApplication::translate("frmmain", "&Help", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("frmmain", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class frmmain: public Ui_frmmain {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMMAIN_H
