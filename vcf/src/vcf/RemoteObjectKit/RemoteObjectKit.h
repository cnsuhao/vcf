/**
*CVS Log info
*$Log$
*Revision 1.1.2.1  2004/04/28 03:45:50  ddiego
*migration towards new directory structure
*
*Revision 1.4.10.1  2004/04/26 21:58:15  marcelloptr
*changes for dir reorganization: _VCF_MACRO_H__
*
*Revision 1.4  2003/02/26 04:30:35  ddiego
*merge of code in the devmain-0-5-9 branch into the current tree.
*most additions are in the area of the current linux port, but the major
*addition to this release is the addition of a Condition class (currently
*still under development) and the change over to using the Delegate class
*exclusively from the older event handler macros.
*
*Revision 1.3.8.1  2002/12/27 23:04:29  marcelloptr
*Improved macros for automatic import/export of libraries. - Warning fixes. - Other Minor Changes.
*
*Revision 1.3  2002/09/12 03:26:03  ddiego
*merged over the changes from the devmain-0-5-5b branch
*
*Revision 1.2.6.1  2002/07/02 05:35:10  marcelloptr
*fixes for vc6, vc7, separated builds, automatic library selection, stlport
*
*Revision 1.2  2002/05/09 03:10:42  ddiego
*merged over code from development branch devmain-0-5-1a into the main CVS trunk
*
*Revision 1.1.2.2  2002/04/08 20:55:29  zzack
*changed include style
*
*Revision 1.1.2.1  2002/04/02 20:37:21  zzack
*changed include
*
*Revision 1.3  2002/02/27 04:16:11  ddiego
*add sub items to TreeItem class for teh tree list control
*added fixes to the RemoteObject stuff
*
*Revision 1.2  2002/01/24 01:46:48  ddiego
*added a cvs "log" comment to the top of all files in vcf/src and vcf/include
*to facilitate change tracking
*
*/

//RemoteObjectKit.h

#ifndef _VCF_REMOTEOBJECTKIT_H__
#define _VCF_REMOTEOBJECTKIT_H__

#include "vcf/RemoteObjectKit/RemoteObjectKitSelectLib.h"
#include "vcf/RemoteObjectKit/RemoteConfig.h"
#include "vcf/NetworkKit/NetworkKit.h"

#include "vcf/RemoteObjectKit/RemoteCommon.h"
#include "vcf/RemoteObjectKit/ClassRegistryEntry.h"
#include "vcf/RemoteObjectKit/ClassServerInstance.h"
#include "vcf/RemoteObjectKit/DistributedClassRegistry.h"
#include "vcf/RemoteObjectKit/DistributedException.h"
#include "vcf/RemoteObjectKit/InstanceID.h"
#include "vcf/RemoteObjectKit/Proxy.h"
#include "vcf/RemoteObjectKit/AbstractDistributedApplication.h"

REMOTEKIT_API void initRemoteObjectKit();
REMOTEKIT_API void terminateRemoteObjectKit();

#endif // _VCF_REMOTEOBJECTKIT_H__


