/********************************************************************************
** Form generated from reading UI file 'dlgaddblog.ui'
**
** Created: Tue Nov 27 22:10:26 2012
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGADDBLOG_H
#define UI_DLGADDBLOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_dlg_add_blog
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *txt_host;
    QLineEdit *txt_path;
    QLineEdit *txt_username;
    QLineEdit *txt_password;
    QPushButton *btn_cancel;
    QPushButton *btn_add;

    void setupUi(QDialog *dlg_add_blog)
    {
        if (dlg_add_blog->objectName().isEmpty())
            dlg_add_blog->setObjectName(QString::fromUtf8("dlg_add_blog"));
        dlg_add_blog->resize(402, 213);
        label = new QLabel(dlg_add_blog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 81, 21));
        label_2 = new QLabel(dlg_add_blog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 50, 81, 21));
        label_3 = new QLabel(dlg_add_blog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 90, 81, 21));
        label_4 = new QLabel(dlg_add_blog);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 130, 91, 21));
        txt_host = new QLineEdit(dlg_add_blog);
        txt_host->setObjectName(QString::fromUtf8("txt_host"));
        txt_host->setGeometry(QRect(100, 10, 271, 25));
        txt_path = new QLineEdit(dlg_add_blog);
        txt_path->setObjectName(QString::fromUtf8("txt_path"));
        txt_path->setGeometry(QRect(100, 50, 271, 25));
        txt_username = new QLineEdit(dlg_add_blog);
        txt_username->setObjectName(QString::fromUtf8("txt_username"));
        txt_username->setGeometry(QRect(100, 90, 271, 25));
        txt_password = new QLineEdit(dlg_add_blog);
        txt_password->setObjectName(QString::fromUtf8("txt_password"));
        txt_password->setEnabled(true);
        txt_password->setGeometry(QRect(100, 130, 271, 25));
        txt_password->setInputMethodHints(Qt::ImhHiddenText|Qt::ImhNoAutoUppercase|Qt::ImhNoPredictiveText);
        txt_password->setEchoMode(QLineEdit::Password);
        btn_cancel = new QPushButton(dlg_add_blog);
        btn_cancel->setObjectName(QString::fromUtf8("btn_cancel"));
        btn_cancel->setGeometry(QRect(110, 170, 88, 27));
        btn_add = new QPushButton(dlg_add_blog);
        btn_add->setObjectName(QString::fromUtf8("btn_add"));
        btn_add->setGeometry(QRect(250, 170, 88, 27));

        retranslateUi(dlg_add_blog);

        QMetaObject::connectSlotsByName(dlg_add_blog);
    } // setupUi

    void retranslateUi(QDialog *dlg_add_blog)
    {
        dlg_add_blog->setWindowTitle(QApplication::translate("dlg_add_blog", "Add Blog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("dlg_add_blog", "Host Name :", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("dlg_add_blog", "Path :", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("dlg_add_blog", "Username :", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("dlg_add_blog", "Password : ", 0, QApplication::UnicodeUTF8));
        txt_password->setText(QString());
        btn_cancel->setText(QApplication::translate("dlg_add_blog", "Cancel", 0, QApplication::UnicodeUTF8));
        btn_add->setText(QApplication::translate("dlg_add_blog", "Add", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class dlg_add_blog: public Ui_dlg_add_blog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGADDBLOG_H
