import QtQuick 2.0
import QtQuick.Controls 2.2
Item {

  Rectangle{
      anchors.fill: parent
      color: "#313539"
      ListModel{
         id:myModel
         ListElement {
              title:"推荐"
              modelSrcG: "qrc:/source/Chat_MsgRecordG.svg"
              modelSrc: "qrc:/source/Chat_MsgRecord.svg"
             }
         ListElement {
              title:"朋友"
             modelSrcG: "qrc:/source/Main_P2PChatG.svg"
             modelSrc: "qrc:/source/Main_P2PChat.svg"
             }
         ListElement {
             title:"电台"
             modelSrcG: "qrc:/source/Mobile_FindG.svg"
             modelSrc: "qrc:/source/Mobile_Find.svg"
             }

      }

      TabBar
      {
          width: parent.width
          id: bar
          height: 60
          spacing: 0
          currentIndex:swipeview.currentIndex
          Repeater {
              id: repeater
              model: myModel

              TabButton {

                  id:btn
                  background: Rectangle{
                           id:btnBack
                           color: "#313539"

                      }
                  height: bar.height
                  contentItem:Column{

                      Text{
                          id: textName
                          width: 30
                          height: 30
                          text: model.title
                          font.family:(model.index === bar.currentIndex)?"微软雅黑" :"微软雅黑 Light"
                          font.pointSize: (model.index === bar.currentIndex)?11 :10
                          anchors.horizontalCenter: parent.horizontalCenter
//                          verticalAlignment: Text.AlignVCenter
//                          horizontalAlignment: Text.AlignHCenter
                          color: "white"

                      }
                      Rectangle{
                         width:35
                         height: 2
                         color: "white"
                         opacity: (model.index === bar.currentIndex)?1 :0
                         id:lineRect
                         anchors.horizontalCenter: parent.horizontalCenter

                         Behavior on opacity{
                           NumberAnimation { duration: 100 }

                         }

                      }
                  }

              }
          }
          onCurrentIndexChanged: {

          }

      }

      SwipeView{
         id:swipeview
         anchors.top:bar.bottom
         currentIndex:bar.currentIndex
         width: parent.width
         height: parent.height-bar.height
         orientation:Qt.Horizontal
         RecommendPage{
             id:page1

         }
         Rectangle{
             id:page2

             color: Qt.rgba(Math.random(),Math.random(),Math.random(),1.0)
         }
         Rectangle{
             id:page3

             color: Qt.rgba(Math.random(),Math.random(),Math.random(),1.0)
         }

      }


  }

}
