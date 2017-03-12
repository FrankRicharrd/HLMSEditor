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

#ifndef MAGUS_TRANSFORMATION_WIDGET_H
#define MAGUS_TRANSFORMATION_WIDGET_H

#include <QWidget>
#include <QVector3D>

QT_BEGIN_NAMESPACE
class QWidget;
QT_END_NAMESPACE

class QComboBox;
class QStringListModel;
class QLineEdit;

namespace Magus
{
    /****************************************************************************
    Widget used for entering position, (Euler) transformation and scaling
    ****************************************************************************/
    class TransformationWidget : public QWidget
    {
        Q_OBJECT

        public:
            enum Transformation {POSITION, ROTATION, SCALE};
            TransformationWidget(QWidget* parent = 0);
            virtual ~TransformationWidget(void);
            const Transformation getCurrentTransformation(void) const;
            const QVector3D getCurrentXYZ(void);
            const QVector3D getPosition(void) const;
            const QVector3D getRotation(void) const;
            const QVector3D getScale(void) const;
            void setPosition(const QVector3D& position);
            void setRotation(const QVector3D& rotation);
            void setScale(const QVector3D& scale);
            void setListEnabled(bool enabled);
            void setCurrentIndex(unsigned int index);
            unsigned int getPrecision (void) const {return mPrecision;}
            void setPrecision (unsigned int precision) {mPrecision = precision;}

        signals:
            void valueChanged(void);

        protected slots:
            void handleSelectionChanged(int index);
            void handleXchanged(const QString &x);
            void handleYchanged(const QString &y);
            void handleZchanged(const QString &z);

        private:
            void sync(void);
            QComboBox* mTransformationCombobox;
            QStringListModel* mModel;
            QLineEdit* mXedit;
            QLineEdit* mYedit;
            QLineEdit* mZedit;
            QVector3D mPosition;
            QVector3D mRotation;
            QVector3D mScale;
            Transformation mTransformation;
            bool selectionChanged;
            unsigned int mPrecision;
            QRegExp mRegularExpression;
            unsigned int getLeftStringIndex(const QString& s);
    };
}

//****************************************************************************/
#endif
