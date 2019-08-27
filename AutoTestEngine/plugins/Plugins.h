#ifndef PLUGINS
#define PLUGINS
#include "AdapterManager.h"

#include "QButtonAdapter.h"
#include "QComboBoxAdpter.h"
#include "QEditAdapter.h"
#include "QMenuAdapter.h"
#include "QTabBarAdapter.h"
#include "QRibbonBarAdapter.h"
#include "QRibbonButtonAdapter.h"

// зЂВс
// Qt
REGISTER_ADAPTER(QAbstractButtonAdapter)
REGISTER_ADAPTER(QComboBoxAdpter)
REGISTER_ADAPTER(QLineEditAdapter)
REGISTER_ADAPTER(QTextEditAdapter)
REGISTER_ADAPTER(QMenuAdapter)
REGISTER_ADAPTER(QTabBarAdapter)
// Ribbon
REGISTER_ADAPTER(QRibbonBarAdapter)
REGISTER_ADAPTER(QRibbonButtonAdapter)

#endif // PLUGINS

