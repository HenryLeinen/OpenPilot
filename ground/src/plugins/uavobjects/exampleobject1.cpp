/**
 ******************************************************************************
 *
 * @file       exampleobject1.cpp
 * @author     The OpenPilot Team, http://www.openpilot.org Copyright (C) 2010.
 * @see        The GNU Public License (GPL) Version 3
 * @addtogroup GCSPlugins GCS Plugins
 * @{
 * @addtogroup UAVObjectsPlugin UAVObjects Plugin
 * @{
 *   
 * @note       Object definition file: exampleobject1.xml. 
 *             This is an automatically generated file.
 *             DO NOT modify manually.
 *
 * @brief      The UAVUObjects GCS plugin
 *****************************************************************************/
/* 
 * This program is free software; you can redistribute it and/or modify 
 * it under the terms of the GNU General Public License as published by 
 * the Free Software Foundation; either version 3 of the License, or 
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful, but 
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY 
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License 
 * for more details.
 * 
 * You should have received a copy of the GNU General Public License along 
 * with this program; if not, write to the Free Software Foundation, Inc., 
 * 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */
#include "exampleobject1.h"
#include "uavobjectfield.h"

const QString ExampleObject1::NAME = QString("ExampleObject1");

/**
 * Constructor
 */
ExampleObject1::ExampleObject1(): UAVDataObject(OBJID, ISSINGLEINST, ISSETTINGS, NAME)
{
    // Create fields
    QList<UAVObjectField*> fields;
    QStringList Field1ElemNames;
    Field1ElemNames.append("0");
    fields.append( new UAVObjectField(QString("Field1"), QString("unit1"), UAVObjectField::INT8, Field1ElemNames, QStringList()) );
    QStringList Field2ElemNames;
    Field2ElemNames.append("0");
    fields.append( new UAVObjectField(QString("Field2"), QString("unit2"), UAVObjectField::INT16, Field2ElemNames, QStringList()) );
    QStringList Field3ElemNames;
    Field3ElemNames.append("0");
    fields.append( new UAVObjectField(QString("Field3"), QString("unit3"), UAVObjectField::INT32, Field3ElemNames, QStringList()) );
    QStringList Field4ElemNames;
    Field4ElemNames.append("0");
    Field4ElemNames.append("1");
    Field4ElemNames.append("2");
    Field4ElemNames.append("3");
    fields.append( new UAVObjectField(QString("Field4"), QString("unit4"), UAVObjectField::FLOAT32, Field4ElemNames, QStringList()) );
    QStringList Field5ElemNames;
    Field5ElemNames.append("0");
    fields.append( new UAVObjectField(QString("Field5"), QString("unit5"), UAVObjectField::UINT8, Field5ElemNames, QStringList()) );
    QStringList Field6ElemNames;
    Field6ElemNames.append("0");
    fields.append( new UAVObjectField(QString("Field6"), QString("unit6"), UAVObjectField::UINT16, Field6ElemNames, QStringList()) );
    QStringList Field7ElemNames;
    Field7ElemNames.append("0");
    fields.append( new UAVObjectField(QString("Field7"), QString("unit7"), UAVObjectField::UINT32, Field7ElemNames, QStringList()) );
    QStringList Field8ElemNames;
    Field8ElemNames.append("0");
    QStringList Field8EnumOptions;
    Field8EnumOptions.append("Option1");
    Field8EnumOptions.append("Option2");
    fields.append( new UAVObjectField(QString("Field8"), QString("unit8"), UAVObjectField::ENUM, Field8ElemNames, Field8EnumOptions) );

    // Initialize object
    initializeFields(fields, (quint8*)&data, NUMBYTES);
    // Set the default field values
    setDefaultFieldValues();
}

/**
 * Get the default metadata for this object
 */
UAVObject::Metadata ExampleObject1::getDefaultMetadata()
{
    UAVObject::Metadata metadata;
    metadata.flightAccess = ACCESS_READWRITE;
    metadata.gcsAccess = ACCESS_READWRITE;
    metadata.gcsTelemetryAcked = 1;
    metadata.gcsTelemetryUpdateMode = UAVObject::UPDATEMODE_PERIODIC;
    metadata.gcsTelemetryUpdatePeriod = 500;
    metadata.flightTelemetryAcked = 1;
    metadata.flightTelemetryUpdateMode = UAVObject::UPDATEMODE_ONCHANGE;
    metadata.flightTelemetryUpdatePeriod = 0;
    metadata.loggingUpdateMode = UAVObject::UPDATEMODE_NEVER;
    metadata.loggingUpdatePeriod = 0;
    return metadata;
}

/**
 * Initialize object fields with the default values.
 * If a default value is not specified the object fields
 * will be initialized to zero.
 */
void ExampleObject1::setDefaultFieldValues()
{

}

/**
 * Get the object data fields
 */
ExampleObject1::DataFields ExampleObject1::getData()
{
    QMutexLocker locker(mutex);
    return data;
}

/**
 * Set the object data fields
 */
void ExampleObject1::setData(const DataFields& data)
{
    QMutexLocker locker(mutex);
    // Get metadata
    Metadata mdata = getMetadata();
    // Update object if the access mode permits
    if ( mdata.gcsAccess == ACCESS_READWRITE )
    {
        this->data = data;
        emit objectUpdatedAuto(this); // trigger object updated event
        emit objectUpdated(this);
    }
}

/**
 * Create a clone of this object, a new instance ID must be specified.
 * Do not use this function directly to create new instances, the
 * UAVObjectManager should be used instead.
 */
UAVDataObject* ExampleObject1::clone(quint32 instID)
{
    ExampleObject1* obj = new ExampleObject1();
    obj->initialize(instID, this->getMetaObject());
    return obj;
}

/**
 * Static function to retrieve an instance of the object.
 */
ExampleObject1* ExampleObject1::GetInstance(UAVObjectManager* objMngr, quint32 instID)
{
    return dynamic_cast<ExampleObject1*>(objMngr->getObject(ExampleObject1::OBJID, instID));
}
