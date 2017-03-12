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
#include "asset_propertywidget_slider_decimal.h"

namespace Magus
{
    //****************************************************************************/
    QtSliderDecimalProperty::QtSliderDecimalProperty(const QString& title, QWidget* parent) : QtProperty(parent)
    {
        mMin = 0.0f;
        mMax = 1.0f;
        mMinRange = 0;
        mMaxRange = 200;
        mStep = 0.005f;
        mPrecision = 2;
        QVBoxLayout* mainLayout = new QVBoxLayout;
        QHBoxLayout* horizontalLayout = new QHBoxLayout;
        QHBoxLayout* editAndSliderLayout = new QHBoxLayout;
        mainLayout->setContentsMargins(5, 0, 5, 0);
        mTitle = new QLabel(title);
        mSlider = new QSlider;
        mEdit = new QLineEdit;
        mRegularExpression = QRegExp("[+-]?([0-9]+\\.([0-9]+)?|\\.[0-9]+)([eE][+-]?[0-9]+)?"); // floating point
        QRegExpValidator* validator = new QRegExpValidator(mRegularExpression);
        mEdit->setValidator(validator);
        mSlider->setOrientation(Qt::Horizontal);
        connect(mSlider, SIGNAL(valueChanged(int)), this, SLOT(sliderValueChanged(void)));
        connect(mEdit, SIGNAL(textChanged(QString)), this, SLOT(editValueChanged(void)));

        // Layout
        horizontalLayout->addWidget(mTitle, 1);
        editAndSliderLayout->addWidget(mEdit, 1);
        editAndSliderLayout->addWidget(mSlider, 2);
        horizontalLayout->addLayout(editAndSliderLayout, 2);
        mainLayout->addLayout(horizontalLayout);
        setLayout(mainLayout);
        mType = SLIDER;
    }

    //****************************************************************************/
    void QtSliderDecimalProperty::setSliderRange (float min, float max, float step)
    {
        mMin = min;
        mMax = max;
        mStep = step;
        mMinRange = (int) (min/step);
        mMaxRange = (int) (max/step);
        mSlider->setRange(mMinRange, mMaxRange);
        mSlider->setTickInterval(1);
    }

    //****************************************************************************/
    void QtSliderDecimalProperty::setValueWithoutEmission (float value)
    {
        // Convert to range
        int intValue = (int)(value/mStep);
        disconnect(mSlider, SIGNAL(valueChanged(int)), this, SLOT(sliderValueChanged(void)));
        mSlider->setValue(intValue);
        connect(mSlider, SIGNAL(valueChanged(int)), this, SLOT(sliderValueChanged(void)));
        QString s = QString::number(value, 'f', mPrecision);
        disconnect(mEdit, SIGNAL(textChanged(QString)), this, SLOT(editValueChanged(void)));
        mEdit->setText(s);
        connect(mEdit, SIGNAL(textChanged(QString)), this, SLOT(editValueChanged(void)));
        editValueChangedWithoutEmission();
    }

    //****************************************************************************/
    void QtSliderDecimalProperty::setValue (float value)
    {
        // Convert to range
        int intValue = (int)(value/mStep);
        mSlider->setValue(intValue);
        QString s = QString::number(value, 'f', mPrecision);
        mEdit->setText(s);
    }

    //****************************************************************************/
    float QtSliderDecimalProperty::getValue (void) const
    {
        return QVariant(mEdit->text()).toFloat();
    }

    //****************************************************************************/
    void QtSliderDecimalProperty::editValueChanged(void)
    {
        editValueChangedWithoutEmission();
        emit valueChanged(this);
    }

    //****************************************************************************/
    void QtSliderDecimalProperty::editValueChangedWithoutEmission(void)
    {
        // Synchronize editbox and slider
        float value = QVariant(mEdit->text()).toFloat();
        int intValue = (int)(value/mStep);
        disconnect(mSlider, SIGNAL(valueChanged(int)), this, SLOT(sliderValueChanged(void)));
        mSlider->setValue(intValue);
        connect(mSlider, SIGNAL(valueChanged(int)), this, SLOT(sliderValueChanged(void)));
    }

    //****************************************************************************/
    void QtSliderDecimalProperty::sliderValueChanged(void)
    {
        sliderValueChangedWithoutEmission();
        emit valueChanged(this);
    }

    //****************************************************************************/
    void QtSliderDecimalProperty::sliderValueChangedWithoutEmission(void)
    {
        // Synchronize editbox and slider
        int intValue = QVariant(mSlider->value()).toInt();
        float value = intValue * mStep;
        QString s = QString::number(value, 'f', mPrecision);
        disconnect(mEdit, SIGNAL(textChanged(QString)), this, SLOT(editValueChanged(void)));
        mEdit->setText(s);
        connect(mEdit, SIGNAL(textChanged(QString)), this, SLOT(editValueChanged(void)));
    }

    //****************************************************************************/
    void QtSliderDecimalProperty::setTitle(const QString title)
    {
        mTitle->setText(title);
    }

    //****************************************************************************/
    void QtSliderDecimalProperty::setPrecision(int precision)
    {
        mPrecision = precision;
    }

    //****************************************************************************/
    int QtSliderDecimalProperty::getPrecision(void)
    {
        return mPrecision;
    }
}
