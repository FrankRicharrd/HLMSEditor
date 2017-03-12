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
#include "asset_propertywidget_slider.h"

namespace Magus
{
    //****************************************************************************/
    QtSliderProperty::QtSliderProperty(const QString& title, QWidget* parent) : QtProperty(parent)
    {
        QVBoxLayout* mainLayout = new QVBoxLayout;
        QHBoxLayout* horizontalLayout = new QHBoxLayout;
        QHBoxLayout* editAndSliderLayout = new QHBoxLayout;
        mainLayout->setContentsMargins(5, 0, 5, 0);
        QLabel* label = new QLabel(title);
        mSlider = new QSlider;
        mEdit = new QLineEdit;
        mRegularExpression = QRegExp("[+-]?([0-9]+\\.([0-9]+)?|\\.[0-9]+)([eE][+-]?[0-9]+)?"); // floating point
        QRegExpValidator* validator = new QRegExpValidator(mRegularExpression);
        mEdit->setValidator(validator);
        mSlider->setOrientation(Qt::Horizontal);
        connect(mSlider, SIGNAL(valueChanged(int)), this, SLOT(sliderValueChanged(void)));
        connect(mEdit, SIGNAL(textChanged(QString)), this, SLOT(editValueChanged(void)));

        // Layout
        horizontalLayout->addWidget(label, 1);
        editAndSliderLayout->addWidget(mEdit, 1);
        editAndSliderLayout->addWidget(mSlider, 2);
        horizontalLayout->addLayout(editAndSliderLayout, 2);
        mainLayout->addLayout(horizontalLayout);
        setLayout(mainLayout);
        mType = SLIDER;
    }

    //****************************************************************************/
    void QtSliderProperty::setSliderRange (int min, int max, int step)
    {
        mSlider->setRange(min, max);
        mSlider->setTickInterval(step);
    }

    //****************************************************************************/
    void QtSliderProperty::setValue (int value)
    {
        mSlider->setValue(value);
        mEdit->setText(QVariant(value).toString());
    }

    //****************************************************************************/
    void QtSliderProperty::setValue (float value)
    {
        mSlider->setValue(value);
        mEdit->setText(QVariant(value).toString());
    }

    //****************************************************************************/
    int QtSliderProperty::getIntValue (void) const
    {
        return QVariant(mEdit->text()).toInt();
    }

    //****************************************************************************/
    float QtSliderProperty::getFloatValue (void) const
    {
        return QVariant(mEdit->text()).toFloat();
    }

    //****************************************************************************/
    void QtSliderProperty::editValueChanged(void)
    {
        // Synchronize editbox and slider
        mSlider->setValue(QVariant(mEdit->text()).toInt());
        emit valueChanged(this);
    }
    //****************************************************************************/
    void QtSliderProperty::sliderValueChanged(void)
    {
        // Synchronize editbox and slider
        mEdit->setText(QVariant(mSlider->value()).toString());
        emit valueChanged(this);
    }
}
