import QtQuick 2.0
import QtGraphicalEffects 1.0
Item {
   id:rooooot
   width: 400
   height: 600
   signal changePage(var str);

   function addItemData(itemName,msgNum,msg){

       itemData1.append({"itemName":itemName,"msgNum":msgNum,"msg":msg})

   }

   function addItemData2(itemName,msgNum,msg){

       itemData2.append({"itemName":itemName,"msgNum":msgNum,"msg":msg})

   }


    ListModel{
       id:itemData1
   }
    ListModel{
       id:itemData2
   }
   Rectangle{
       id:root
       height: parent.height-footer.height
       width: parent.width
       color: "#F4F4F4"

       Flickable{

            clip:true
            anchors.fill:parent
            contentWidth: column.width
            contentHeight: column.height+header.height
            flickableDirection : Flickable.VerticalFlick //只允许垂直滑动
            boundsBehavior:Flickable.StopAtBounds

            Rectangle{
                id:header
                width: root.width
                height: root.height/6
                color: "#F08080"
                Rectangle {
                      width:  parent.height/2
                      height:  parent.height/2
                      color:Qt.rgba(Math.random(),Math.random(),Math.random(),0)
                      anchors.verticalCenter:parent.verticalCenter
                      anchors.left: parent.left
                      anchors.leftMargin: 10


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
                          radius: width/2.
                      }

                      OpacityMask {
                          anchors.fill: parent
                          source: img
                          maskSource: mask
                      }
                  }
            }
            Column {
                anchors.top:header.bottom
                id: column
                spacing: 10
                Column{
                    Repeater{
                        id:list1
                        model:itemData1

                         Rectangle{
                             width: root.width
                             height: 50
                             color:itemArea.pressed ? "#DBDBDB" :"white"
                             Text {
                                 anchors.left: parent.left
                                 anchors.leftMargin: 20
                                 anchors.verticalCenter: parent.verticalCenter
                                 id: name
                                 text: model.itemName
                                 font.family: "微软雅黑 Light"

                             }
                             //圆点消息提醒
                             Rectangle{
                                 width: 20
                                 height: 16
                                 color: "red"
                                 visible: model.msgNum>0?true:false
                                 radius: 8
                                 anchors.right: parent.right
                                 anchors.rightMargin: 10
                                 anchors.verticalCenter: parent.verticalCenter
                                 Text {
                                     anchors.centerIn: parent
                                     text: model.msgNum
                                     color: "white"
                                 }
                             }
                             //文字提醒
                             Text {
                                 anchors.right: parent.right
                                 anchors.rightMargin: 10
                                  anchors.verticalCenter: parent.verticalCenter
                                 text: qsTr(model.msg)
                                 font.family: "微软雅黑 Light"
                                 color: "#778899"
                                 font.pointSize: 6
                                 visible: model.msg===""? false:true
                             }

                             MouseArea{
                                id:itemArea
                                anchors.fill: parent
                                onClicked: {
                                        rooooot.changePage(model.itemName)
                                }

                             }
                         }

                    }

                }
                Column{
                    Repeater{

                        model: ["我的好友","附近的人"]

                        Rectangle{
                            width: root.width
                            height: 50
                            color:itemArea2.pressed ? "#DBDBDB" :"white"
                            Text {
                                anchors.left: parent.left
                                anchors.leftMargin: 20
                                anchors.verticalCenter: parent.verticalCenter
                                id: name2
                                text: modelData
                                font.family: "微软雅黑 Light"

                            }

                            MouseArea{
                               id:itemArea2
                               anchors.fill: parent
                               onClicked: {
                                       rooooot.changePage(modelData)
                               }

                            }
                        }

                    }

                }
                Column{
                    Repeater{
                        id:list2
                        model:itemData2

                         Rectangle{
                             width: root.width
                             height: 50
                             color:itemArea3.pressed ? "#DBDBDB" :"white"
                             Text {
                                 anchors.left: parent.left
                                 anchors.leftMargin: 20
                                 anchors.verticalCenter: parent.verticalCenter
                                 id: name3
                                 text: model.itemName
                                 font.family: "微软雅黑 Light"

                             }
                             Rectangle{
                                 width: 8
                                 height: 8
                                 color: "red"
                                 visible: model.msgNum>0?true:false
                                 radius: 4
                                 anchors.right: parent.right
                                 anchors.rightMargin: 10
                                 anchors.verticalCenter: parent.verticalCenter

                             }
                             MouseArea{
                                id:itemArea3
                                anchors.fill: parent
                                onClicked: {
                                  rooooot.changePage(model.itemName)
                                }

                             }
                         }

                    }

                }



            }

       }

   }
   Rectangle{
      id:footer
      width: parent.width
      height: 50
      anchors.top:root.bottom

      Row{
          Repeater{
              model: ["夜间模式","设置","退出"]

              Rectangle{
                   height: footer.height
                   width: footer.width/3
                   color: footerArea.pressed?"#DBDBDB" :"white"
                   Text {
                       id: footerName
                       text: qsTr(modelData)
                       anchors.centerIn: parent
                       font.family: "微软雅黑 Light"
                   }
                   MouseArea{
                       id:footerArea
                       anchors.fill: parent
                       onClicked: {
                         rooooot.changePage(modelData)
                       }
                   }

              }

          }
      }

   }
}
