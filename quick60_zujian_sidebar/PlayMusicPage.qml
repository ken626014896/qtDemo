import QtQuick 2.0
import QtQuick.Controls 2.2
import QtGraphicalEffects 1.0
import QtQuick.Layouts 1.3
import QtMultimedia 5.8
Item {
    id:root
    signal back()
    property alias rwidth: rectangle.width
    property alias rheight: rectangle.height
    property bool isStart: false //开始与暂停标记
    property var timedata: new Date();
    function mscString(miao){
       timedata.setTime(miao)

       return Qt.formatTime(timedata,"mm:ss")
    }

    ListModel{
       id:listData
       ListElement {
                name: "Apple"
                author:"脸红"
                url: "qrc:/source/Some.mp3"
            }
       ListElement {
                name: "Orange"
                author:"xx"
                url: "qrc:/source/Some.mp3"
            }
       ListElement {
                name: "Banana"
                author:"벌써"
                url: "qrc:/source/Some.mp3"
            }
    }
    MediaPlayer {
        id: playMusic
        volume: 0.1
        autoLoad:true
        source: "qrc:/source/Some.mp3"
        onDurationChanged: {
            totalTime.text=mscString(duration)
            control.to=duration
            //初始化转动角度和时间
            repeater.itemAt(swipeView.currentIndex).picAnimation.duration=duration
            repeater.itemAt(swipeView.currentIndex).picAnimation.to=duration/30000*360

            //显示歌曲名称和作者

//            musicName.text=metaData.title
//            musicAuthor.text=metaData.author

              }
         onPositionChanged: {
            currentTime.text=mscString(position)
            control.value=position


              }

          }
    Rectangle {
        id: rectangle
        color: "#ffffff"


        Rectangle {  //播放页面顶部
            id: headerRect

            width: 400
            height: 50
            color: "#313539"

            Image {
                id: image
                anchors.left: parent.left
                anchors.leftMargin: 10
                sourceSize.height: parent.height*0.8
                sourceSize.width: height
                anchors.verticalCenter: parent.verticalCenter
                source: "source/chevron_left.ico"
                MouseArea{
                   anchors.fill: parent
                   onClicked: {
                       root.back()
                   }
                }
            }
            Rectangle{
               id:musicInfo
               anchors.left: image.right
               height: parent.height

               Column{
                   Text {
                       id: musicName
                       text:swipeView.currentIndex
                       font.pointSize: 16

                       color: "white"
                   }

                   Text {
                       id: musicAuthor
                       text: qsTr("text")
                       color: "#DCDCDC"
                   }

               }
            }

        }
        Rectangle {   //播放页面中间部位
            width: parent.width
            height: parent.height - headerRect.height - bottomRect.height
            id: circleRect
            anchors.top: headerRect.bottom

            SwipeView {
                id: swipeView

                anchors.fill: parent

                Repeater{
                    model:listData
                    id:repeater
                    delegate: Rectangle{
                        property alias picAnimation: picAnimation
                        property var musicUrl: model.url
                        property var musicname: model.name
                        property var musicauthor: model.author

                        Rectangle{
                           width: 350
                           height: 350
                           radius: width/2
                           color: "black"
                           anchors.centerIn: parent
                           Rectangle {
                                 id:willCircleRect
                                 width: 240
                                 height: 240
                                 color: "black"
                                 radius: width/2
                                 anchors.centerIn: parent


                                 Image {
                                     id: img
                                     source: "qrc:/source/kenn.jpg"
                                     sourceSize: Qt.size(parent.width, parent.height)
                                     smooth: true
                                     visible: false
                                 }

                                 Rectangle{
                                     id:mask

                                     anchors.fill: parent
                                     radius: width/2
                                 }

                                 OpacityMask {
                                     anchors.fill: parent
                                     source: img
                                     maskSource: mask
                                 }
                                 RotationAnimation{
                                    id:picAnimation
                                    target: willCircleRect
                                    to:360
                                    duration: 30000

                                 }
                             }
                        }



                    }


                }
                onCurrentIndexChanged: {
                    playMusic.stop()
                    playMusic.source=repeater.itemAt(currentIndex).musicUrl
                    musicName.text=repeater.itemAt(currentIndex).musicname
                    musicAuthor.text=repeater.itemAt(currentIndex).musicauthor


                }
            }
        }
        Rectangle {   //播放页面底部操作栏
            id: bottomRect
            y: 598
            height: 200
            color: "#ffffff"
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 0
            anchors.right: parent.right
            anchors.rightMargin: 0
            anchors.left: parent.left
            anchors.leftMargin: 0

            Rectangle {
                id: btnRect
                width: 400
                height: 100
                color: "#ffffff"
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 0

                Image {
                    id: image2
                    x: 188
                    y: 38
                    width: 50
                    height: 50
                    sourceSize.height: 50
                    sourceSize.width: 50
                    fillMode: Image.PreserveAspectFit
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter
                    source: isStart?"qrc:/source/zhangting.ico":"qrc:/source/video_player.ico"
                    MouseArea{
                        anchors.fill: parent
                        onClicked: {
                            console.log("begain")


                            if(!isStart)
                            {
                               repeater.itemAt(swipeView.currentIndex).picAnimation.restart()
                                playMusic.play()
                            }
                            else
                            {

                                playMusic.pause()

                                repeater.itemAt(swipeView.currentIndex).picAnimation.pause()


                            }

                             isStart=!isStart

                        }

                    }
                }

                Image {
                    id: image11
                    x: 105
                    y: 40
                    source: "source/left.ico"
                }

                Image {
                    id: image22
                    x: 270
                    y: 40
                    source: "source/right.ico"
                }

                Image {
                    id: image33
                    x: 25
                    y: 39
                    source: "source/looping.ico"
                }

                Image {
                    id: image44
                    x: 354
                    y: 43
                    source: "source/player_list.ico"


                }
            }

            Rectangle {
                id: slideRect
                width: 400
                height: 50
                color: "#ffffff"
                anchors.bottom: btnRect.top
                anchors.bottomMargin: 0

                Text {
                    id: currentTime
                    color: "#787474"
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.right: control.left
                }
                Slider {

                    id: control
                    width: 308
                    height: 30
                    from: 0
                    value: 0
                    to: 120
                    anchors.centerIn: parent
                    background: Rectangle {
                        x: control.leftPadding
                        y: control.topPadding + control.availableHeight / 2 - height / 2
                        implicitWidth: 720
                        implicitHeight: 4
                        width: control.availableWidth
                        height: implicitHeight
                        radius: 2
                        color: "#787474"

                        Rectangle {
                            width: control.visualPosition * parent.width
                            height: parent.height
                            color: "#B82525"
                            radius: 2
                        }
                    }

                    handle: Rectangle {
                        x: control.leftPadding + control.visualPosition
                           * (control.availableWidth - width)
                        y: control.topPadding + control.availableHeight / 2 - height / 2
                        implicitWidth: 18
                        implicitHeight: 18
                        radius: 9
                        color: control.pressed ? "#f0f0f0" : "#f6f6f6"
                        border.color: "#bdbebf"
                        Rectangle {
                            anchors.centerIn: parent
                            width: 6
                            height: 6
                            radius: 3
                            color: "#B82525"
                        }
                    }
                    onMoved: {
                        playMusic.seek(value)
                    }
                }
                Text {
                    id: totalTime
                    color: "#787474"
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.left: control.right
                }
            }
        }
    }
}
