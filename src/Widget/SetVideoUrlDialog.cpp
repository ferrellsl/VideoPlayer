#include "SetVideoUrlDialog.h"
#include "ui_SetVideoUrlDialog.h"

#include <QFileDialog>

#include "AppConfig.h"

SetVideoUrlDialog::SetVideoUrlDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SetVideoUrlDialog)
{
    ui->setupUi(this);

    connect(ui->pushButton_selectFile,   &QPushButton::clicked, this, &SetVideoUrlDialog::slotBtnClick);

}

SetVideoUrlDialog::~SetVideoUrlDialog()
{
    delete ui;
}

void SetVideoUrlDialog::setVideoUrl(const QString &url)
{
    ui->lineEdit_fileUrl->setText(url);
}

QString SetVideoUrlDialog::getVideoUrl()
{
    QString url = ui->lineEdit_fileUrl->text();
    return url;
}

void SetVideoUrlDialog::slotBtnClick(bool isChecked)
{
    if (QObject::sender() == ui->pushButton_selectFile)
    {
        QString s = QFileDialog::getOpenFileName(
                   this, QStringLiteral("Select file"),
                    AppConfig::gVideoFilePath,//初始目录
                    QStringLiteral("Video File (*.flv *.ts *.rmvb *.avi *.MP4 *.mkv);;")
                    +QStringLiteral("Audio File (*.mp3 *.wma *.wav);;")
                    +QStringLiteral("All files (*.*)"));
        if (!s.isEmpty())
        {
            ui->lineEdit_fileUrl->setText(s);
        }
    }
}
