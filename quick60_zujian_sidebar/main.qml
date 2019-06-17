import QtQuick 2.0
import QtQuick.Window 2.2
import QtQuick.Controls 1.2
Window {
    visible: true
    width: 400
    height: 800
    title: qsTr("Hello World")
    property bool isVisit: false
    property real dpi:Screen.pixelDensity
   Rectangle{
       id:homepage
       anchors.fill: parent
       color: "white"

       Loader{
         sourceComponent:homepageComp

       }

   }

   Component{
      id:homepageComp
      HomePage{
         width: homepage.width
         height:homepage.height
         onGetEdgePage: {

            display.running=true
         }

      }

   }
   SideBar{
       id:sidepage
       width: parent.width*0.8
       height: parent.height
       x:0-width
       Component.onCompleted: {


          addItemData("我的信息",99,"")
           addItemData("我的会员",0,"")
           addItemData("云村有票",0,"")
           addItemData("商城",0,"")
           addItemData("推荐",0,"")
           addItemData("在线听歌免流量",0,"已开通")

           addItemData2("个性换肤",99,"")
            addItemData2("听歌识曲",0,"")
            addItemData2("定时停止播放",0,"")
            addItemData2("扫一扫",0,"")
            addItemData2("推荐",0,"")
            addItemData2("在线听歌免流量",0,"")
           addItemData2("个性换肤",99,"")
            addItemData2("听歌识曲",0,"")
            addItemData2("定时停止播放",0,"")
            addItemData2("扫一扫",0,"")
            addItemData2("推荐",0,"")
            addItemData2("在线听歌免流量",0,"")



     }
       onChangePage: {
           console.log(str)
       }
    }
   PropertyAnimation {
       id:display
       target: sidepage
       property: "x"
       from:0-sidepage.width
       to:0
       duration: 200
       easing.type: Easing.InOutQuad
       onStopped: {
              backRect.visible=true
              isVisit=true
       }
   }

   PropertyAnimation {
       id:disappear
       target: sidepage
       property: "x"
       from:0
       to:0-sidepage.width
       duration: 200
       easing.type: Easing.InOutQuad
       onStarted: {
          backRect.visible=false
           isVisit=false
       }
   }
   Rectangle{
      id:backRect
      height: parent.height
      width: parent.width-sidepage.width
      color: "black"
      visible: false
      opacity: 0.5
      anchors.right: homepage.right
      MouseArea{
         anchors.fill: parent
         onClicked: {
            disappear.running=true
             console.log(dpi)


         }

      }

   }


}

