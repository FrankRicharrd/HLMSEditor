/****************************************************************************
**
** Copyright (C) 2016
**
** This file is generated by the Magus toolkit
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
****************************************************************************/

// Include
#include <QVBoxLayout>
#include <QLabel>
#include <QRegExpValidator>
#include "asset_propertywidget_quaternion.h"

namespace Magus
{
    //****************************************************************************/
    QtQuaternionProperty::QtQuaternionProperty(const QString& title,
                                               qreal w,
                                               qreal x,
                                               qreal y,
                                               qreal z,
                                               QWidget* parent) :
        QtProperty(parent),
        mPrecision(3)
    {
        QVBoxLayout* mainLayout = new QVBoxLayout;
        QHBoxLayout* horizontalLayout = new QHBoxLayout;
        QHBoxLayout* quaternionLayout = new QHBoxLayout;
        QHBoxLayout* wLayout = new QHBoxLayout;
        QHBoxLayout* xLayout = new QHBoxLayout;
        QHBoxLayout* yLayout = new QHBoxLayout;
        QHBoxLayout* zLayout = new QHBoxLayout;
        mainLayout->setContentsMargins(5, 0, 5, 0);
        QLabel* label = new QLabel(title);
        QLabel* wLabel = new QLabel(QString("W"));
        QLabel* xLabel = new QLabel(QString("X"));
        QLabel* yLabel = new QLabel(QString("Y"));
        QLabel* zLabel = new QLabel(QString("Z"));
        mWEdit = new QLineEdit;
        mXEdit = new QLineEdit;
        mYEdit = new QLineEdit;
        mZEdit = new QLineEdit;
        mRegularExpression = QRegExp("[+-]?([0-9]+\\.([0-9]+)?|\\.[0-9]+)([eE][+-]?[0-9]+)?"); // floating point
        QRegExpValidator* validator = new QRegExpValidator(mRegularExpression);
        mWEdit->setValidator(validator);
        mXEdit->setValidator(validator);
        mYEdit->setValidator(validator);
        mZEdit->setValidator(validator);
        setQuaternion(w, x, y, z);
        connect(mWEdit, SIGNAL(textEdited(QString)), this, SLOT(propertyValueChanged(void)));
        connect(mXEdit, SIGNAL(textEdited(QString)), this, SLOT(propertyValueChanged(void)));
        connect(mYEdit, SIGNAL(textEdited(QString)), this, SLOT(propertyValueChanged(void)));
        connect(mZEdit, SIGNAL(textEdited(QString)), this, SLOT(propertyValueChanged(void)));

        // Layout
        wLayout->addWidget(wLabel, 1);
        wLayout->addWidget(mWEdit, 100);
        xLayout->addWidget(xLabel, 1);
        xLayout->addWidget(mXEdit, 100);
        yLayout->addWidget(yLabel, 1);
        yLayout->addWidget(mYEdit, 100);
        zLayout->addWidget(zLabel, 1);
        zLayout->addWidget(mZEdit, 100);
        quaternionLayout->addLayout(wLayout);
        quaternionLayout->addLayout(xLayout);
        quaternionLayout->addLayout(yLayout);
        quaternionLayout->addLayout(zLayout);
        horizontalLayout->addWidget(label, 1);
        horizontalLayout->addLayout(quaternionLayout, 2);
        mainLayout->addLayout(horizontalLayout);
        setLayout(mainLayout);
        mType = QUATERNION;
    }

    //****************************************************************************/
    void QtQuaternionProperty::setQuaternion(qreal w, qreal x, qreal y, qreal z)
    {
        setW(w);
        setX(x);
        setY(y);
        setZ(z);
    }

    //****************************************************************************/
    void QtQuaternionProperty::setQuaternion(const QQuaternion& q)
    {
        setW(q.scalar());
        setX(q.x());
        setY(q.y());
        setZ(q.z());
    }

    //****************************************************************************/
    void QtQuaternionProperty::setW (qreal w)
    {
        mWEdit->setText(QString::number(w, 'f', mPrecision));
    }

    //****************************************************************************/
    void QtQuaternionProperty::setX (qreal x)
    {
        mXEdit->setText(QString::number(x, 'f', mPrecision));
    }

    //****************************************************************************/
    void QtQuaternionProperty::setY (qreal y)
    {
        mYEdit->setText(QString::number(y, 'f', mPrecision));
    }

    //****************************************************************************/
    void QtQuaternionProperty::setZ (qreal z)
    {
        mZEdit->setText(QString::number(z, 'f', mPrecision));
    }

    //****************************************************************************/
    const qreal QtQuaternionProperty::getW (void) const
    {
        double d = mWEdit->text().toDouble();
        return QVariant(d).toReal();
    }

    //****************************************************************************/
    const qreal QtQuaternionProperty::getX (void) const
    {
        double d = mXEdit->text().toDouble();
        return QVariant(d).toReal();
    }

    //****************************************************************************/
    const qreal QtQuaternionProperty::getY (void) const
    {
        double d = mYEdit->text().toDouble();
        return QVariant(d).toReal();
    }

    //****************************************************************************/
    const qreal QtQuaternionProperty::getZ (void) const
    {
        double d = mZEdit->text().toDouble();
        return QVariant(d).toReal();
    }

    //****************************************************************************/
    void QtQuaternionProperty::propertyValueChanged(void)
    {
        emit valueChanged(this);
    }
}

