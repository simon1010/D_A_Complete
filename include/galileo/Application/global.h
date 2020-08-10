#pragma once
#include <QtCore/qglobal.h>

#ifdef Application_EXPORTS
# define Application_EXPORT_IMPORT_API Q_DECL_EXPORT
#else
# define Application_EXPORT_IMPORT_API Q_DECL_IMPORT
#endif
