import QtQuick 2.0
import QtQuick.Controls 2.2

Item {
     id:root
     Rectangle{
         anchors.fill: parent
         id:back
         color: "white"
         Flickable{
             clip: true
             anchors.fill: parent
             contentHeight: picRect.height+other.height
             contentWidth: parent.width
             flickableDirection : Flickable.VerticalFlick //只允许垂直滑动
             boundsBehavior:Flickable.StopAtBounds

             Rectangle{
                 id:picRect
                 width: root.width
                 height: 180
                 Rectangle{
                    anchors.top:parent.top
                    width: parent.width
                    height: (parent.height/3)*2
                    color:"#313539"
                 }
                 Rectangle{
                    anchors.bottom: parent.bottom
                    color: "white"
                    width: parent.width
                    height: parent.height/3
                 }
                 Rectangle{
                     //轮播组件的区域
                    anchors.centerIn: parent
                    width: parent.width-15
                    height: parent.height

                    radius: 10
                    PageIndicator {
                         id: indicator
                         count: swipeView.count
                         currentIndex: swipeView.currentIndex
                         interactive: true //可以点击
                         anchors.bottom: swipeView.bottom
                         z:1
                         anchors.horizontalCenter: parent.horizontalCenter
                     }
                    SwipeView {
                        //轮播组件
                            clip:true
                            id: swipeView
                            width: parent.width
                            height: parent.height
                            currentIndex:indicator.currentIndex
                            orientation:Qt.Horizontal
                            Rectangle{
                                radius: 10
//                                Image {
//                                    //id= name
//                                    fillMode: Image.PreserveAspectCrop
//                                    source: "http://www.xuzhaolong.site/static/homepage/images/contentImg/IYzFGf7VNgetFyPcicwxTVJw7k1f7JUgcEq64qHxWf3I3pjj1z6OZxCZNB7mXzgB9FE3CXeFKSD7Ug3icZWTQx1A.jpg"
//                                    anchors.fill: parent
//                                }
                                color: Qt.rgba(Math.random(),Math.random(),Math.random(),1.0)
                            }
                            Rectangle{
                                radius: 10
//                                Image {
//                                    //id= name
//                                    fillMode: Image.PreserveAspectCrop
//                                    source: "http://www.xuzhaolong.site/static/homepage/images/contentImg/IYzFGf7VNgetFyPcicwxTVJw7k1f7JUgcEq64qHxWf3I3pjj1z6OZxCZNB7mXzgB9FE3CXeFKSD7Ug3icZWTQx1A.jpg"
//                                    anchors.fill: parent
//                                }
                                color: Qt.rgba(Math.random(),Math.random(),Math.random(),1.0)
                            }
                            Rectangle{
                                radius: 10
//                                Image {
//                                    //id= name
//                                    fillMode: Image.PreserveAspectCrop
//                                    source: "http://www.xuzhaolong.site/static/homepage/images/contentImg/IYzFGf7VNgetFyPcicwxTVJw7k1f7JUgcEq64qHxWf3I3pjj1z6OZxCZNB7mXzgB9FE3CXeFKSD7Ug3icZWTQx1A.jpg"
//                                    anchors.fill: parent
//                                }
                                color: Qt.rgba(Math.random(),Math.random(),Math.random(),1.0)
                            }
                            Rectangle{
                                radius: 10
//                                Image {
//                                    //id= name
//                                    fillMode: Image.PreserveAspectCrop
//                                    source: "http://www.xuzhaolong.site/static/homepage/images/contentImg/IYzFGf7VNgetFyPcicwxTVJw7k1f7JUgcEq64qHxWf3I3pjj1z6OZxCZNB7mXzgB9FE3CXeFKSD7Ug3icZWTQx1A.jpg"
//                                    anchors.fill: parent
//                                }
                                color: Qt.rgba(Math.random(),Math.random(),Math.random(),1.0)
                            }



                        }
                 }

             }
             Rectangle{
               id:other
               anchors.top:picRect.bottom
               color: "white"
               width: root.width
               height: 1000

                  Rectangle{
                     id:fourBtn
                     width: parent.width
                     height: 120

                     Row{
                        spacing: 50
                        anchors.centerIn:parent
                        Repeater{
                          model:["私人FM","每日推荐","歌单","排行榜"]

                          Column{
                             spacing: 10
                             Rectangle{
                                 width: 60
                                 height: 60
                                 radius: 30
                                 color: "#313539"

                             }

                             Text {
                                 anchors.horizontalCenter: parent.horizontalCenter
                                 id: name
                                 text: modelData
                                 font.family: "微软雅黑"
                                 color: "#313539"


                             }


                          }

                        }

                     }

                  }

                  Text {
                      anchors.topMargin: 20
                      anchors.top:fourBtn.bottom
                      anchors.left: parent.left
                      anchors.leftMargin: 10
                      id: recomText
                      text: qsTr("推荐歌单")
                      font.family: "微软雅黑"
                      font.pointSize: 10
                      color: "#313539"


                  }

                  Grid{
                      anchors.top:recomText.bottom
                      anchors.topMargin: 20
                      anchors.horizontalCenter: fourBtn.horizontalCenter
                      columns: 3
                      spacing: 10

                      Repeater{
                          model:6
                          Rectangle{
                              width: (root.width-40)/3
                              height: 210
                              color: Qt.rgba(Math.random(),Math.random(),Math.random(),1.0)

                          }

                      }

                  }





             }


         }


     }
}
