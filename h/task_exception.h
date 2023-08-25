#ifndef TASK_EXCEPTION_H
#define TASK_EXCEPTION_H

#include <QString>

class task_exception
{
private:
    QString m_error;
public:
    task_exception();
    task_exception(QString error)
        : m_error(error){}
    QString getError() { return m_error; }
};

#endif // TASK_EXCEPTION_H
