/*
 *	@Package : WODPRESS XMLRPC 
 *  @Author : Pham Van Diep
 * 	@Contact : pndhainam@hotmail.com
 */

#include <QtXml>
#include <QtCore>

#include "mvariant.h"

MVariant::MVariant()
{
	this->variable.setValue(QVariant());
}

/** Constructs a copy of the variant, p, passed as the argument
 *  to this constructor. */
MVariant::MVariant( const QVariant &val )
{
	this->variable = val;
}



/** Constructs a new variant with an integer value, val. */
MVariant::MVariant ( int val )
{
	this->variable.setValue(val);
}

/** Constructs a new variant with an integer value, val. */
MVariant::MVariant ( uint val )
{
	this->variable.setValue(val);
}

/** Constructs a new variant with a boolean value, val. */
MVariant::MVariant ( bool val )
{
	this->variable.setValue(val);
}


/** Constructs a new variant with a double value, val. */
MVariant::MVariant ( double val )
{
	this->variable.setValue(val);
}

/** Constructs a new variant with an QByteArray value, val. */
MVariant::MVariant ( const QByteArray & val )
{
	this->variable.setValue(val);
}

/** Constructs a new variant with a string value, val. */
MVariant::MVariant ( const QString & val )
{
	this->variable.setValue(val);
}

/** Constructs a new variant with a strings list value, val. */
MVariant::MVariant ( const QStringList & val )
{
	this->variable.setValue(val);
}

/** Constructs a new variant with a char value, val. XmlRPC
string type will be used. */ 
MVariant::MVariant ( const QChar & c )
{ 
	this->variable.setValue(c);
}

/** Constructs a new variant with a date time value, val. */
MVariant::MVariant ( const QDateTime & val )
{
	this->variable.setValue(val);
}

/** Constructs a new variant with a list value, val. */
/**
 * Constructs a new variant from XmlRPC xml element node.
 * note name must be "value"
 */

MVariant::~MVariant()
{
}


void MVariant::tostring(QVariant params )
{
    
//    qDebug()<<"\n"<<params.type()<<"\n"<<params;
    switch ( params.type() ) {
    case QVariant::Int:
    case QVariant::UInt:
        this->items << QString::number( params.toInt() );
      this->ret<<this->items;
      //this->items.clear();
        break;

    case QVariant::String:
        this->items <<params.toString();
        this->ret<<this->items;
       //this->items.clear();
        break;

    case QVariant::Double:
        this->items << QString::number( params.toDouble() );
        this->ret<<this->items;
        //this->items.clear();
        break;

    case QVariant::DateTime:
        this->items << params.toDateTime().toString();
		this->ret<<this->items;
        //this->items.clear();
          break;

    case QVariant::Bool:
        this->items << ( params.toBool() ? "true" : "false" );
        this->ret<<this->items;
        //this->items.clear();
        break;

    case QVariant::ByteArray:
        {
            QString data = params.toByteArray().toBase64();
            if ( data.length() > 128 ) {
                data = data.left(64)+"...";
            }
            this->items << data;
          this->ret<<this->items;
          // this->items.clear();
            break;
        }

    case QVariant::StringList:
    case QVariant::List:
        {   //this->items.clear();    
            QListIterator<QVariant> it( params.toList() );
            while( it.hasNext() ) {
				//it.next();
                this->tostring(it.next());
            }
            break;
        }
    case QVariant::Map:
        {
			
			//QStringList item;
            QMapIterator<QString,QVariant> it( params.toMap());
            while( it.hasNext() ) {
               it.next();
               //this->items.clear();
				this->items<<it.key();		
				this->tostring(it.value());
				//this->ret<<this->items;
				this->items.clear();
            }
            
            break;
        }
      default:
			break;
    
    }
   
}
QList<QStringList> MVariant::get_qlistqstringlist(){
this->tostring(this->variable);
/*#if(XMLRPC_DEBUG)
foreach(QStringList item,this->ret){
 qDebug()<<"\n"<<item;
}
#endif
*/
return this->ret;	
}



