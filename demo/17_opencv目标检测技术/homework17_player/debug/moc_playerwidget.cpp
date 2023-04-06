/****************************************************************************
** Meta object code from reading C++ file 'playerwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../playerwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'playerwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PlayerWidget_t {
    QByteArrayData data[13];
    char stringdata0[254];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PlayerWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PlayerWidget_t qt_meta_stringdata_PlayerWidget = {
    {
QT_MOC_LITERAL(0, 0, 12), // "PlayerWidget"
QT_MOC_LITERAL(1, 13, 8), // "getFrame"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 11), // "nowFrameNum"
QT_MOC_LITERAL(4, 35, 5), // "Frame"
QT_MOC_LITERAL(5, 41, 21), // "on_playButton_clicked"
QT_MOC_LITERAL(6, 63, 21), // "on_stopButton_clicked"
QT_MOC_LITERAL(7, 85, 20), // "on_endButton_clicked"
QT_MOC_LITERAL(8, 106, 24), // "on_restartButton_clicked"
QT_MOC_LITERAL(9, 131, 23), // "on_recordButton_clicked"
QT_MOC_LITERAL(10, 155, 29), // "on_finishRecordButton_clicked"
QT_MOC_LITERAL(11, 185, 33), // "on_horizontalSlider_sliderPre..."
QT_MOC_LITERAL(12, 219, 34) // "on_horizontalSlider_sliderRel..."

    },
    "PlayerWidget\0getFrame\0\0nowFrameNum\0"
    "Frame\0on_playButton_clicked\0"
    "on_stopButton_clicked\0on_endButton_clicked\0"
    "on_restartButton_clicked\0"
    "on_recordButton_clicked\0"
    "on_finishRecordButton_clicked\0"
    "on_horizontalSlider_sliderPressed\0"
    "on_horizontalSlider_sliderReleased"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PlayerWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   59,    2, 0x0a /* Public */,
       5,    0,   64,    2, 0x08 /* Private */,
       6,    0,   65,    2, 0x08 /* Private */,
       7,    0,   66,    2, 0x08 /* Private */,
       8,    0,   67,    2, 0x08 /* Private */,
       9,    0,   68,    2, 0x08 /* Private */,
      10,    0,   69,    2, 0x08 /* Private */,
      11,    0,   70,    2, 0x08 /* Private */,
      12,    0,   71,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QImage,    3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void PlayerWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PlayerWidget *_t = static_cast<PlayerWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->getFrame((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QImage(*)>(_a[2]))); break;
        case 1: _t->on_playButton_clicked(); break;
        case 2: _t->on_stopButton_clicked(); break;
        case 3: _t->on_endButton_clicked(); break;
        case 4: _t->on_restartButton_clicked(); break;
        case 5: _t->on_recordButton_clicked(); break;
        case 6: _t->on_finishRecordButton_clicked(); break;
        case 7: _t->on_horizontalSlider_sliderPressed(); break;
        case 8: _t->on_horizontalSlider_sliderReleased(); break;
        default: ;
        }
    }
}

const QMetaObject PlayerWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_PlayerWidget.data,
      qt_meta_data_PlayerWidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *PlayerWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PlayerWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PlayerWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int PlayerWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
