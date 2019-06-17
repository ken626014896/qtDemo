import QtQuick 2.0
import QtQuick.Controls 2.2
Rectangle{
    id:root

    signal getEdgePage()
    property var isDisplay: false

    property var detaObj

    function onBack(){
        playArea.enabled=true
        detaObj.destroy()

    }

    Rectangle{
        id:header
        color: "#313539"
        width: parent.width
        height: 60

        Image {
            id: name
            source: "qrc:/source/settings.ico"
            fillMode: Image.PreserveAspectCrop
            anchors.verticalCenter: parent.verticalCenter
            sourceSize.width:30
            sourceSize.height:30
            MouseArea{
                anchors.fill: parent
                onClicked: {
                   root.getEdgePage()

                }
            }


        }
        ListModel{
           id:myModel
           ListElement {
                modelSrcG: "qrc:/source/Chat_MsgRecordG.svg"
                modelSrc: "qrc:/source/Chat_MsgRecord.svg"
               }
           ListElement {
               modelSrcG: "qrc:/source/Main_P2PChatG.svg"
               modelSrc: "qrc:/source/Main_P2PChat.svg"
               }
           ListElement {
               modelSrcG: "qrc:/source/Mobile_FindG.svg"
               modelSrc: "qrc:/source/Mobile_Find.svg"
               }

        }
        TabBar
        {
            anchors.centerIn: parent
            id: bar
            currentIndex:swipeview.currentIndex
            height: 30
            spacing: 0
            Repeater {
                id: repeater
                model: myModel
                TabButton {
                    background: Rectangle{
                             color: "#313539"

                        }

                    height: bar.height
                    contentItem:
                       // property  alias textColor: text.textColor
                        Image{
                            id: tabImage
                            width: 30
                            height: 30
                            anchors.horizontalCenter: parent.horizontalCenter
                            source: (model.index === bar.currentIndex) ? modelSrcG : modelSrc
                        }





                }
            }

        }




    }

    SwipeView{
       id:swipeview
       anchors.top:header.bottom
       currentIndex:bar.currentIndex
       width: parent.width
       height: parent.height-header.height-play.height
       orientation:Qt.Horizontal
       Rectangle{
           id:page1

           color: Qt.rgba(Math.random(),Math.random(),Math.random(),1.0)
       }
       MusicPage{
           id:page2


       }
       Rectangle{
           id:page3

           color: Qt.rgba(Math.random(),Math.random(),Math.random(),1.0)
       }


    }

    Rectangle{
      id:play
      width: parent.width
      height: 70
      color: "white"
      anchors.bottom: parent.bottom
      MouseArea{
         id:playArea
         anchors.fill: parent
         onClicked: {
             //准备跳转页面

              var detaComp=Qt.createComponent("PlayMusicPage.qml")

              detaObj=detaComp.createObject(root, {"focus": true,"rwidth":root.width,"rheight":root.height});
              playArea.enabled=false
              detaObj.back.connect(root.onBack)
         }

      }
      Rectangle{
         id:playPic
         width: 50
         height: 50
         radius: 5
         anchors.verticalCenter: parent.verticalCenter
         anchors.left: parent.left
         anchors.leftMargin: 10
         color: Qt.rgba(Math.random(),Math.random(),Math.random(),1.0)


      }

      Image{
          id:playList
          source: "qrc:/source/settings.ico"
          sourceSize.height: parent.height*0.5
          sourceSize.width: height
          fillMode: Image.PreserveAspectCrop
          anchors.verticalCenter: parent.verticalCenter
          anchors.right: parent.right
          anchors.rightMargin: 10
          MouseArea{
             anchors.fill: parent
             onClicked: {
                 if(isDisplay)//隐藏播放列表
                 {
                     musicList.y=root.height
                     playArea.enabled=true

                 }


                  else //显示播放列表
                  {
                     musicList.y=root.height/2
                      playArea.enabled=false

                 }

                 isDisplay=!isDisplay

             }

          }



      }


    }
    Rectangle{
       id:musicList
       width: parent.width
       height: parent.height+20
       z:1
       y:parent.height
       color: Qt.rgba(Math.random(),Math.random(),Math.random(),1.0)
       radius: 20

       Behavior on y{

           NumberAnimation{
              duration: 100
           }
       }

    }



}
