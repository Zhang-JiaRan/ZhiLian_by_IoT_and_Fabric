<template>
  
    
    <div>
      <a-spin size="large" :spinning="spinning">
        <a-card style="border: 100px;box-shadow: 0 3px 8px 0 rgba(0, 0, 0, 0.1);border-radius: 30px;" class="shouye">
        <a-row :gutter="5">
          <a-col :span="16" style="text-align: left;">
            <!-- <a-card hoverable @click="visible = true" style="margin-bottom: 20px; width: 800px;text-align: center;;"> -->
            <a-row>
              <a-col :span="6">
                <a-select v-model="selectVehicleIndex" placeholder="请选择配送车辆">
                  <a-select-option :value="index" v-for="(item, index) in vehicles" :key="index">
                    {{ item.type }} : {{ item.number }}
                  </a-select-option>
                </a-select>
              </a-col>
              <a-col :span="6" style="margin-left: 0px;margin-right: 60px;">
                <a-input v-model="form.license" addon-before="当前开车司机" default-value="李四" />
              </a-col>
              <a-col :span="7">
                <a-input v-model="form.license" addon-before="联系方式" default-value="17837194857" />
              </a-col>
            </a-row>

          </a-col>
        </a-row>
        <a-row :gutter="20" style="margin-top: 20px;">
          <a-col :span="16" class="item">
            <a-card hoverable class="add-item" @click="visible = true"
              style="box-shadow: 0 3px 8px 0 rgba(0, 0, 0, 0.1);border-radius: 30px;">

              <!-- <CardLineChart></CardLineChart> -->
              <div id="main" style="height:300px;"></div>

            </a-card>
          </a-col>
          <a-col :span="8" class="item">
            <a-card hoverable class="add-item" @click="visible = true">
              <a-row :gutter="16" align="middle">
                <img src="../../assets/driver.jpg"
                  style="margin-top: 0px;height:200px;width: 300px;box-shadow: 0 3px 8px 0 rgba(0, 0, 0, 0.1);" />
              </a-row>
              <a-row style="margin-top: 40px;font-size: medium;">
                <a-col span="12">
                  <p>车内人员</p>
                </a-col>
                <a-col span="12">
                  <p>司机温度</p>
                </a-col>
              </a-row>
              <a-row :gutter="16" align="middle" style="margin-top: 0px;">
                <a-col :span="3" style="text-align: left; ">
                  <img src="../../assets/driverdetect.png" alt="" class="img3">
                </a-col>
                <a-col :span="9">
                  <div v-if="P">
                    <p style="text-align: left;margin-left: 22px;margin-top: 40px; font-size:x-large;font-weight:400;">有
                    </p>
                  </div>
                  <div v-else>
                    <p style="text-align: left;margin-left: 22px;margin-top: 40px; font-size:x-large;font-weight:400;">无
                    </p>
                  </div>
                </a-col>
                <a-col :span="3">
                  <img src="../../assets/humantemp.png" alt="" class="img31">
                </a-col>
                <a-col :span="9">
                  <a-row :gutter="30">
                    <p style="margin-left: 0px;margin-top: 42px; font-size:x-large;font-weight:400;">{{ T }}℃</p>
                  </a-row>
                </a-col>
              </a-row>
              <!-- <a-row>
                <p class="name4">温度:{{ TM }}°C</p>
              <p class="name4">湿度:{{ HM }}</p>
              </a-row> -->

            </a-card>
          </a-col>

          <a-col :span="6" class="item">
            <a-card hoverable class="add-1" @click="visible = true">
              <a-row :gutter="16" align="middle">
                <a-col :span="6">
                  <img src="../../assets/temp.png" alt="" class="img2" style="margin-top: 25px;">
                </a-col>
                <a-col :span="18">
                  <a-row :gutter="30">
                    <p style="margin-top:20px; margin-left: 20px; font-size: large;font-weight:1000; ">车内温度</p>
                  </a-row>
                  <a-row :gutter="30">
                    <p style="margin-left: 20px; font-size: xx-large;font-weight:400;font-style: italic;color:indianred;">
                      {{ TM }}℃</p>
                  </a-row>
                </a-col>
              </a-row>
              <!-- <div class="login-info">
                <p class="name5">烟雾</p>
                <p class="name6">{{ MQ }}</p>
              </div> -->
            </a-card>
          </a-col>
          <a-col :span="6" class="item">
            <a-card hoverable class="add-1" @click="visible = true">
              <a-row :gutter="16" align="middle">
                <a-col :span="6">
                  <img src="../../assets/humid.png" alt="" class="img2" style="margin-top: 25px;">
                </a-col>
                <a-col :span="18">
                  <a-row :gutter="30">
                    <p style="margin-top:20px; margin-left: 20px; font-size: large;font-weight:1000; ">车内湿度</p>
                  </a-row>
                  <a-row :gutter="30">
                    <p style="margin-left: 20px; font-size: xx-large;font-weight:400;font-style: italic;color:indianred;">
                      {{ HM }}%</p>
                  </a-row>
                </a-col>
              </a-row>
            </a-card>
          </a-col>
          <a-col :span="6" class="item">
            <a-card hoverable class="add-1" @click="visible = true">
              <a-row :gutter="16" align="middle">
                <a-col :span="6">
                  <img src="../../assets/smoke.png" alt="" class="img2" style="margin-top: 25px;">
                </a-col>
                <a-col :span="18">
                  <a-row :gutter="30">
                    <p style="margin-top:20px; margin-left: 20px; font-size: large;font-weight:1000; ">烟雾浓度</p>
                  </a-row>
                  <a-row :gutter="30">
                    <p style="margin-left: 20px; font-size: xx-large;font-weight:400;font-style: italic;color:indianred;">
                      {{ MQ }}%</p>
                  </a-row>
                </a-col>
              </a-row>
            </a-card>
          </a-col>
          <a-col :span="6" class="item">
            <a-card v-if="F" hoverable class="add-1" @click="visible = true" style="background-color:crimson">
              <a-row :gutter="16" align="middle">
                <a-col :span="6">
                  <img src="../../assets/fire.png" alt="" class="img2" style="margin-top: 25px;">
                </a-col>
                <a-col :span="18">
                  <a-row :gutter="30">
                    <p style="margin-top:20px; margin-left: 20px; font-size: large;font-weight:1000; ">火焰检测</p>
                  </a-row>
                  <a-row :gutter="30">
                    <div>
                      <p
                        style="margin-left: 20px; font-size: xx-large;font-weight:400;font-style: italic;color:darkblue;">
                        火</p>
                    </div>
                  </a-row>
                </a-col>
              </a-row>
            </a-card>
            <a-card v-else hoverable class="add-1" @click="visible = true">
              <a-row :gutter="16" align="middle">
                <a-col :span="6">
                  <img src="../../assets/fire.png" alt="" class="img2" style="margin-top: 25px;">
                </a-col>
                <a-col :span="18">
                  <a-row :gutter="30">
                    <p style="margin-top:20px; margin-left: 20px; font-size: large;font-weight:1000; ">火焰检测</p>
                  </a-row>
                  <a-row :gutter="30">
                    <div>
                      <p
                        style="margin-left: 20px; font-size: xx-large;font-weight:400;font-style: italic;color:darkblue;">
                        无</p>
                    </div>
                  </a-row>
                </a-col>
              </a-row>
            </a-card>
          </a-col>
          <a-col :span="24" class="item">
            <a-card hoverable class="add-2" @click="visible = true" style="box-shadow: 0 3px 8px 0 rgba(0, 0, 0, 0.1);border-radius: 30px;">
              <div>
                <p style="font-size: xx-large;font-weight:400; text-align: center;">当前车辆位置：（{{ JD | toFixed(2) }}，{{ WD | toFixed(2) }}）</p>
              </div>
              <div class="add-map" style="margin-top: 20px;">
                <drivermap style="border-radius: 30px; border: 1px dashed; height: 400px;" />
              </div>
            </a-card>
          </a-col>
        </a-row>
      </a-card>
      </a-spin>
    </div>
  
</template>
<script>
import { FindAllCanUse, SaveDistribution } from "../../api/distribution";
import * as echarts from 'echarts';
import drivermap from "../../components/drivermap.vue";
import CardLineChart from '../../components/CardLineChart';
import axios from 'axios'
import { Getdata } from "@/api/getdata";

export default {
  name: "tracking",
  components: {
    drivermap,
    CardLineChart
  },
  data() {
    return {
      selectVehicleIndex: 0,
      vehicles: [],
      TM: '',
      HM: '',
      MQ: '',
      JD: 0,
      WD: 0,
      P: false,
      F: false,
      R: '',
      T: '',
      visible: false,
      spinning: false,
      form: {
        number: '京A0000',
        type: '快递',
        driving: false,
      },
      data: [],
      imgList: [
        require('../../assets/warehouse0.svg'),
        require('../../assets/warehouse1.svg'),
        require('../../assets/warehouse2.svg'),]
    }
  },

  mounted() {
    setInterval(this.GetResult,500);
    this.DrawChart();
    FindAllCanUse().then((res) => {
      if (res.status) {
        this.vehicles = res.data.vehicles
      }
      console.log(this.vehicles)
    })
    // this.loadData();
    // this.GetResult();
  },


  methods: {
    DrawChart() {
      // 基于准备好的dom，初始化echarts实例
      let myChart = this.$echarts.init(document.getElementById("main"));
      // 指定图表的配置项和数据
      let option = {

        title: {
          text: '监测数据历史记录',
          subtext: '12小时',
          x: 'center'
        },

        legend: { // 图例配置选项
          orient: 'horizontal', //图例布局方式：水平 'horizontal' 、垂直 'vertical'
          x: 'left', // 横向放置位置，选项：'center'、'left'、'right'、'number'（横向值 px）
          y: 'top',// 纵向放置位置，选项：'top'、'bottom'、'center'、'number'（纵向值 px）
          data: ['温度/℃', '湿度/%']
        },
        grid: {  // 图表距离边框的距离，可用百分比和数字（px）配置
          top: '20%',
          left: '3%',
          right: '10%',
          bottom: 'opx',
          containLabel: true
        },

        xAxis: {
          name: '时刻',
          type: 'category',
          data: ['3', '4', '5', '6', '7', '8', '9', '10', '11', '12', '13', '14',]
        },

        yAxis: {
          name: '标准单位数值',
          type: 'value',
          min: -10, // 配置 Y 轴刻度最小值
          max: 70,  // 配置 Y 轴刻度最大值
          splitNumber: 10,  // 配置 Y 轴数值间隔
        },

        series: [
          // {
          //   name: '猜想',
          //   data: [454, 226, 891, 978, 901, 581, 400, 543, 272, 955, 1294, 1581],
          //   type: 'line',
          //   symbolSize: function (value) {  // 点的大小跟随数值增加而变大
          //     return value / 150;
          //   },
          //   symbol: 'circle',
          //   itemStyle: {
          //     normal: {
          //       label: {
          //         show: true
          //       },
          //       lineStyle: {
          //         color: 'rgba(0,0,0,0)'// 折线颜色设置为0，即只显示点，不显示折线
          //       }
          //     }
          //   }
          // },

          {
            name: '温度/℃',
            data: [-1.07, -3.52, -7.40, -9.68, -6.47, -5.70, -3.43, -7.57, -5.47, -7.62, -1.70, -6.65],
            type: 'line',
            symbolSize: 8,  //设置折线上圆点大小
            itemStyle: {
              normal: {
                label: {
                  show: true // 在折线拐点上显示数据
                },
                lineStyle: {
                  width: 3,  // 设置虚线宽度
                  type: 'dotted'  // 虚线'dotted' 实线'solid'
                }
              }
            }
          },

          {
            name: '湿度/%',
            data: [56, 30, 54, 57, 31, 24, 47, 50, 42, 45, 61, 45],
            type: 'line',
            symbol: 'circle', // 实心圆点
            smooth: 0.5, // 设置折线弧度
            symbolSize: 8,  //设置折线上圆点大小
            itemStyle: {
              normal: {
                label: {
                  show: true // 在折线拐点上显示数据
                },
                lineStyle: {
                  width: 3,  // 设置虚线宽度
                  type: 'solid'  // 虚线'dotted' 实线'solid'
                }
              }
            }
          }
        ],
        color: [/*'#3366CC', */'#FFCC99', '#99CC33'] // 三个折线的颜色
      }
      option && myChart.setOption(option);
      // 指定图表的配置项和数据
    },

    GetResult() {
      Getdata().then((res) => {
        if (res.status) {
          if (JSON.parse(res.data.data).data.datastreams[0].datapoints[0].value == "0")
            this.P = true;
          else
            this.P = false;
          this.R = JSON.parse(res.data.data).data.datastreams[1].datapoints[0].value
          this.MQ = JSON.parse(res.data.data).data.datastreams[2].datapoints[0].value
          this.T = JSON.parse(res.data.data).data.datastreams[3].datapoints[0].value
          this.HM = JSON.parse(res.data.data).data.datastreams[4].datapoints[0].value
          if (JSON.parse(res.data.data).data.datastreams[5].datapoints[0].value == "0")
            this.F = true;
          else
            this.F = false;
          this.TM = JSON.parse(res.data.data).data.datastreams[6].datapoints[0].value
          this.JD = (Number(JSON.parse(res.data.data).data.datastreams[8].datapoints[0].value)/1000000).toFixed(5)
          this.WD = (Number(JSON.parse(res.data.data).data.datastreams[9].datapoints[0].value)/1000000).toFixed(5)
        }
        console.log(this.getResult)
      }).catch((err) => {
        console.log(this.getResult)
        getResult = err
      })
    },

    loadData() {
      this.spinning = true
      FindAllVehicle().then((res) => {
        if (res.status) this.data = res
        setTimeout(() => {
          this.spinning = false
        }, 600)
      })
    },

    submit() {
      SaveVehicle(this.form).then((res) => {
        if (res.status) this.$message.success("添加成功")
        this.visible = false
        this.loadData()
      })
    },
    drawChart() {
      // 基于准备好的dom，初始化echarts实例
      let myChart = this.$echarts.init(document.getElementById("main"));
      // 指定图表的配置项和数据
      let option = {
        title: {
          // text: 'Stacked Line'
        },
        tooltip: {
          trigger: 'axis'
        },
        legend: {
          data: ['Email', 'Union Ads', 'Video Ads', 'Direct', 'Search Engine']
        },
        grid: {
          left: '3%',
          right: '4%',
          bottom: '3%',
          containLabel: true
        },
        toolbox: {
          feature: {
            saveAsImage: {}
          }
        },
        xAxis: {
          type: 'category',
          boundaryGap: false,
          data: ['Mon', 'Tue', 'Wed', 'Thu', 'Fri', 'Sat', 'Sun']
        },
        yAxis: {
          type: 'value'
        },
        series: [
          {
            name: 'Email',
            type: 'line',
            stack: 'Total',
            data: [120, 132, 101, 134, 90, 230, 210]
          },
          {
            name: 'Union Ads',
            type: 'line',
            stack: 'Total',
            data: [220, 182, 191, 234, 290, 330, 310]
          },
          {
            name: 'Video Ads',
            type: 'line',
            stack: 'Total',
            data: [150, 232, 201, 154, 190, 330, 410]
          },
          {
            name: 'Direct',
            type: 'line',
            stack: 'Total',
            data: [320, 332, 301, 334, 390, 330, 320]
          },
          {
            name: 'Search Engine',
            type: 'line',
            stack: 'Total',
            data: [820, 932, 901, 934, 1290, 1330, 1320]
          }
        ]
      };
      option && myChart.setOption(option);
      // 指定图表的配置项和数据
    }
  },
  // mounted() {
  //   this.drawChart();
  // }
}
</script>
<style scoped>
* {
  margin: 0;
  padding: 0;
}

.add-1 {
  text-align: center;
  line-height: 50px;
  height: 200px;
  box-shadow: 0 3px 8px 0 rgba(0, 0, 0, 0.1);
  border-radius: 5%;
}

.add-1:hover {
  border: 1px #5a84fd;
  color: #5a84fd;
}

.add-2 {
  text-align: left;
  line-height: 30px;
  height: 500px;
  box-shadow: 0 3px 8px 0 rgba(0, 0, 0, 0.1);
  border-radius: 30px;
}

.add-2:hover {
  border: 1px  #5a84fd;
  color: #5a84fd;
}

.add-3 {
  text-align: center;
  height: 350px;
  border: 1px dashed #91949c;
  border-radius: 1%;
}

.add-4 {
  text-align: center;
  height: 300px;
  border: 1px dashed #91949c;
  border-radius: 1%;
}

.add-item {
  text-align: center;
  line-height: 0px;
  height: 370px;
  /* border: 1px dashed #91949c; */
  box-shadow: 0 3px 8px 0 rgba(0, 0, 0, 0.1);
  border-radius: 30px;
}

.add-item:hover {
  border: 1px #5a84fd;
  color: #5a84fd;
}

.item {
  margin-bottom: 20px;
  border-radius: 1%;
}

.image {
  width: 80px;
  height: 80px;
  margin-left: 20px;
}

.user {
  padding-bottom: 20px;
  display: flex;
  align-items: center;
  margin: 0;
  padding: 0;
}

.name {
  font-size: 20px;
  margin-top: 20px;
  margin-left: 40px;
}

.name1 {
  font-size: 15px;
  margin-top: 30px;
}

.name2 {
  font-size: 14px;
  margin-top: 30px;
}

.name3 {
  font-size: 40px;
  margin-top: 30px;
}

.name4 {
  line-height: 50px;
  font-size: 30px;
  margin-top: 30px;
}

.name5 {
  line-height: 30px;
  font-size: 50px;
  margin-top: 30px;
}

.name6 {
  line-height: 100px;
  font-size: 30px;
}

.access {
  color: #999999;
}

.img1 {
  /* margin-right: 40px; */
  width: 110px;
  height: 110px;
  border-radius: 50%;
}

.img2 {
  /* margin-right: 40px; */
  width: 90px;
  height: 90px;
}

.login-info {
  line-height: 10px;
  font-size: 14px;
  color: #999999;
}

.img3 {
  /* margin-right: 40px; */
  margin-top: 17px;
  margin-right: 50px;
  width: 50px;
  height: 50px;
}

.img31 {
  /* margin-right: 40px; */
  margin-top: 17px;
  margin-right: 100px;
  width: 50px;
  height: 50px;
}</style>