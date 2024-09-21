#ifndef LANGUAGEMODEL_H
#define LANGUAGEMODEL_H

#include <QString>

class LanguageModel {
public:
    LanguageModel();

    QString dsName() const;
    void setDsName(const QString &dsName);

    QString dsIcon() const;
    void setDsIcon(const QString &dsIcon);

    QString dsCompleteFile() const;
    void setDsCompleteFile(const QString &dsCompleteFile);

    QString dsHighlightFile() const;
    void setDsHighlightFile(const QString &dsHighlightFile);

private:
    QString _dsName;
    QString _dsIcon;
    QString _dsCompleteFile;
    QString _dsHighlightFile;
};

#endif // LANGUAGEMODEL_H
