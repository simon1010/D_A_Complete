#pragma once
#include <QtCore/qglobal.h>

#ifdef Framework_EXPORTS
# define Framework_EXPORT_IMPORT_API Q_DECL_EXPORT
#else
# define Framework_EXPORT_IMPORT_API Q_DECL_IMPORT
#endif
