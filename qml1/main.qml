import QtQuick 2.3
import QtQuick.Window 2.2

Window {
    id: sans // 声明属性：<name>: <value>
    visible: true
    width: 640; height: 480
    color: "#D8D8D8" // 颜色属性
    // 声明一个嵌套元素（根元素的子元素）
    Image {
        id: rocket
        x: (parent.width - width)/2; y: 40 // 使用 parent 引用父元素
        source: 'rocket.png'
    }
    // 根元素的另一个子元素
    Text {
        id: thisLabel
        // 该元素未命名
        y: rocket.y + rocket.height + 20 // 使用 id 引用元素
        width: sans.width // 使用 id 引用元素
        horizontalAlignment: Text.AlignHCenter

        default property var defaultText

        // (4) 自定义属性
        property int times: 24
        // (5) 属性别名
        property alias anotherTimes: thisLabel.times
        // (6) 文本和值
        text: "Rocket " + thisLabel.anotherTimes + thisLabel.defaultText
        // (7) 字体属性组
        //font.family: "Ubuntu"
        //font.pixelSize: 24
        font {
            family: "Ubuntu"
            pixelSize: 18
        }

        // (8) 附加属性 KeyNavigation
        KeyNavigation.tab: otherLabel
        // (9) 属性值改变的信号处理回调
        onHeightChanged: console.log('height:', height)
        // 接收键盘事件需要设置 focus
        focus: true
        // 根据 focus 值改变颜色
        color: focus?"black":"red"

        property int counts: 0
        Keys.onSpacePressed: xxinc()
        Keys.onEscapePressed: thisLabel.text = ""
        function xxinc() {
            counts += 1
            text = "You pressed SPACE " + counts + " times"
        }
    }

    MouseArea {
        anchors.fill: parent
        onDoubleClicked: Qt.quit()
    }
}
