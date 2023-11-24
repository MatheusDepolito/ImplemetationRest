pragma Singleton

import QtQuick 2.15
import QtCore

Item {
  id: root
  property alias telaConfigs: telaConfigs
  property var telaConfigsAtual: telaConfigs.telaMainWindow

  QtObject {
    id: telaConfigs
    readonly property var telaLogin: ["Login Dashboard Educacional", ""]
    readonly property var telaMainWindow: ["Dashboard Educacional", ""]
  }

  readonly property string title: telaConfigsAtual[0]
}
