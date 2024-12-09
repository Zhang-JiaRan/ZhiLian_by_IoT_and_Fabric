<template>
  <div>
    <a-card style="border: 0px;box-shadow: 0 3px 8px 0 rgba(0, 0, 0, 0.1);border-radius: 30px;" class="shouye">
      <a-button size="large" class="editable-add-btn" @click="addneeds = true"
        style="margin-bottom: 20px;box-shadow: 0 3px 8px 0 rgba(0, 0, 0, 0);border-radius: 30px;">
        <a-icon type="plus" />
        填写需求
      </a-button>
      <a-row :gutter="20">
        <a-col :span="8" class="item">
          <a-card v-if="show" hoverable class="add-item" @click="visible = true"
            style="box-shadow: 0 3px 8px 0 rgba(0, 0, 0, 0.1);border-radius: 30px;">
            <a-select v-model="selectedOption" style="width: 270px; margin-left: 20px;margin-bottom: 20px;">
              <a-select-option v-for="option in options" :key="option.value" :value="option.value">
                {{ option.label }}
              </a-select-option>
            </a-select>
            <a-card v-for="(card, index) in cards" :key="index"
              style="box-shadow: 0 3px 8px 0 rgba(0, 0, 0, 0.1);border-radius: 30px;margin-bottom: 5px;">
              <div v-for="(item, index) in card" :key="index">{{ item }}</div>
            </a-card>
            <!-- <a-select v-if!="show" v-model="selectedOption" style="width: 300px; margin-left: 20px;margin-bottom: 20px;">
              <a-select-option v-if!="show" v-for="option in preoptions" :key="option.value" :value="option.value" >
                {{ option.label }}
              </a-select-option>
            </a-select>
            <a-card v-if!="show" v-for="(card, index) in precards" :key="index" style="box-shadow: 0 3px 8px 0 rgba(0, 0, 0, 0.1);border-radius: 30px;margin-bottom: 5px;">
              <div v-if!="show" v-for="(item, index) in card" :key="index">{{ item }}</div>
            </a-card> -->
          </a-card>
          <a-card v-else hoverable class="add-item" @click="visible = true"
            style="box-shadow: 0 3px 8px 0 rgba(0, 0, 0, 0.1);border-radius: 30px;">
            <a-select v-model="selectedOption" style="width: 270px; margin-left: 20px;margin-bottom: 20px;"
              @change="onOptionChange">
              <a-select-option v-for="option in preoptions" :key="option.value" :value="option.value">
                {{ option.label }}
              </a-select-option>
            </a-select>
            <a-card v-for="(card, index) in precards" :key="index"
              style="box-shadow: 0 3px 8px 0 rgba(0, 0, 0, 0.1);border-radius: 30px;margin-bottom: 5px;height: 100px;">
              <div v-for="(item, index) in card" :key="index">{{ item }}</div>
            </a-card>
          </a-card>
        </a-col>
        <a-col :span="16" class="item">
          <a-card hoverable class="add-item" @click="visible = true"
            style="box-shadow: 0 3px 8px 0 rgba(0, 0, 0, 0.1);border-radius: 30px;">
            <a-row>
              路径规划
            </a-row>
            <a-row>
              <a-col :span="12">
                <img v-if="selectedOption === '1'" src="../../assets/1.jpg"
                  style="margin-top: 0px; margin-bottom: 20px;height:310px;width: 325px;box-shadow: 0 3px 8px 0 rgba(0, 0, 0, 0.1);border-radius: 30px;" />
                <img v-if="selectedOption === '2'" src="../../assets/2.jpg"
                  style="margin-top: 0px; margin-bottom: 20px;height:310px;width: 325px;box-shadow: 0 3px 8px 0 rgba(0, 0, 0, 0.1);border-radius: 30px;" />
                <img v-if="selectedOption === '3'" src="../../assets/3.jpg"
                  style="margin-top: 0px; margin-bottom: 20px;height:400px;width: 325px;box-shadow: 0 3px 8px 0 rgba(0, 0, 0, 0.1);border-radius: 30px;" />
              </a-col>
              <a-col :span="12">
                <img v-if="selectedOption === '1'" src="../../assets/11.jpg"
                  style="margin-top: 0px; margin-bottom: 20px;height:310px;width: 325px;box-shadow: 0 3px 8px 0 rgba(0, 0, 0, 0.1);border-radius: 30px;" />
                <img v-if="selectedOption === '2'" src="../../assets/22.jpg"
                  style="margin-top: 0px; margin-bottom: 20px;height:310px;width: 325px;box-shadow: 0 3px 8px 0 rgba(0, 0, 0, 0.1);border-radius: 30px;" />
                <img v-if="selectedOption === '3'" src="../../assets/33.jpg"
                  style="margin-top: 0px; margin-bottom: 20px;height:400px;width: 325px;box-shadow: 0 3px 8px 0 rgba(0, 0, 0, 0.1);border-radius: 30px;" />
              </a-col>
            </a-row>
          </a-card>
        </a-col>
      </a-row>
    </a-card>

    <a-modal title="填写需求" :visible="addneeds" @ok="addneeds = false, show = true" @cancel="addneeds = false" :width=1000>
      <a-button type="primary" shape="circle" @click="addNew" style="margin-bottom: 5px; "> + </a-button>
      <div v-for="(item, idx) in formData" :key="idx" style="margin-top: 20px;">
        <a-row :gutter="10">
          <a-col :span="2" style="margin-top: 4px;font-size: small; font-weight: 20px;">
            <h3>需求{{ idx + 1 }}</h3>
          </a-col>
          <a-col :span="4">
            <a-input v-model="item.receiver" addon-before="收货人" placeholder="王五" />
          </a-col>
          <a-col :span="4" style="margin-left: 50px;">
            <a-select default-value="货物种类" style="width: 100px" @change="handleChange">
              <a-select-option value="冷藏食品">
                冷藏食品
              </a-select-option>
              <a-select-option value="花卉植物">
                花卉植物
              </a-select-option>
              <a-select-option value="化学药品">
                化学药品
              </a-select-option>
            </a-select>
            <!-- <a-select v-model="item.goods" style="width: 100px;">
              <a-select-option value="冷藏食品">冷藏食品</a-select-option>
              <a-select-option value="花卉植物">花卉植物</a-select-option>
              <a-select-option value="化学药品">化学药品</a-select-option>
            </a-select> -->
          </a-col>
          <a-col :span="10">
            <a-input v-model="item.address" addon-before="收货地址" placeholder="山东省青岛市黄岛区成功西路66号" />
          </a-col>
        </a-row>
        <a-row :gutter="10" style="margin-top: 5px;">
          <a-col :span="2">
          </a-col>
          <a-col :span="10">
            <a-range-picker :locale="locale" :show-time="{ format: 'HH:mm' }" format="YYYY-MM-DD HH:mm" @change="onChange" 
              @ok="onOk" />
            <!-- <a-date-picker v-model="item.startDate" show-time format="YYYY-MM-DD HH:mm:ss"
              placeholder="起始时间"></a-date-picker>
          </a-col>
          <a-col :span="5" style="margin-left: 24px;">
            <a-date-picker v-model="item.startDate" show-time format="YYYY-MM-DD HH:mm:ss"
              placeholder="结束时间"></a-date-picker> -->
          </a-col>
          <a-col :span="8" style="margin-left: 24px;">
            <a-input v-model="item.contact" addon-before="联系方式" placeholder="17856473920" />
          </a-col>
        </a-row>

        <a @click="deleteItem(idx)" style="font-size: x-small;">删除此需求</a>




      </div>
    </a-modal>
  </div>
</template>

<script>
import locale from 'ant-design-vue/es/date-picker/locale/zh_CN.js';
export default {
  data() {
    return {
      show: false,
      selectedOption: null,
      preoptions: [
        { label: '', value: '' }
      ],
      options: [
        { label: '物流单号：3283714813921', value: '1', map1: false, map2: false, map3: false },
        { label: '物流单号：4129481741851', value: '2', map1: false, map2: false, map3: false },
        { label: '物流单号：7231238941291', value: '3', map1: false, map2: false, map3: false },
      ],
      precards: [
        [
          ' ',
          ' ',
          ' ',
          ' ',
          ' ',
          ' ',
        ],
      ],
      cards: [
        [
          '',
          '',
          '',
          '',
          '',
          '',
        ],
      ],
      locale,
      addneeds: false,
      formData: [
        {
          receiver: '',
          goods: '',
          address: '',
          startDate: null,
          endDate: null,
          contact: ''
        }
      ]
    }
  },
  methods: {
    onOptionChange(value) {
      const selectedOption = this.options.find(option => option.value === value)
      selectedOption['map' + value] = true
    },
    onChange(value, dateString) {
      console.log('Selected Time: ', value);
      console.log('Formatted Selected Time: ', dateString);
    },
    onOk(value) {
      console.log('onOk: ', value);
    },
    handleChange(value) {
      console.log(`selected ${value}`);
    },
    addNew() {
      this.formData.push({
        receiver: '',
        goods: '',
        address: '',
        startDate: null,
        endDate: null,
        contact: ''
      });
    },
    deleteItem(idx) {
      if (this.formData.length === 1) {
        return;
      }
      this.formData.splice(idx, 1);
    },
    moveUp(idx) {
      const item = this.formData.splice(idx, 1);
      this.formData.splice(idx - 1, 0, item[0]);
    },
    moveDown(idx) {
      const item = this.formData.splice(idx, 1);
      this.formData.splice(idx + 1, 0, item[0]);
    }
  },
  watch: {
    selectedOption(value) {
      switch (value) {
        case '1':
          this.cards = [
            [
              '收货人：万三',
              '联系方式：13864221728',
              '货物：花卉植物',
              '时间：2023-03-01',
              '地点：凤凰地',
              '分配货车：闽D00002',
            ],
            [
              '收货人：朱三',
              '联系方式：18554943181',
              '货物：花卉植物',
              '时间：2021-03-01',
              '地点：灵山湾.龙玺',
              '分配货车：闽D00002',
            ],
            [
              '收货人：卜四',
              '联系方式：16776232970',
              '货物：花卉植物',
              '时间：2023-03-01',
              '地点：西寨村',
              '分配货车：闽D00002',
            ],
            [
              '收货人：张六',
              '联系方式：13864292022',
              '货物：花卉植物',
              '时间：2023-03-01',
              '地点：天一公寓(海滨九路)',
              '分配货车：闽D00002',
            ],
            [
              '收货人：李四',
              '联系方式：13864221722',
              '货物：花卉植物',
              '时间：2023-03-01',
              '地点：宇坤超市',
              '分配货车：闽D00002',
            ],
          ]
          break
        case '2':
          this.cards = [
            [
              '收货人：刘三',
              '联系方式：13864221728',
              '货物：冷藏食品',
              '时间：2021-03-01',
              '地点：创科园',
              '分配货车：鲁A00001',
            ],
            [
              '收货人：王五',
              '联系方式：13864292722',
              '货物：冷藏食品',
              '时间：2021-03-01',
              '地点：青岛小镇',
              '分配货车：鲁A00001',
            ],[
              '收货人：王二',
              '联系方式：17753840238',
              '货物：冷藏食品',
              '时间：2021-03-01',
              '地点：赵家河村委会',
              '分配货车：鲁A00001',
            ],[
              '收货人：赵三',
              '联系方式：18105421950',
              '货物：冷藏食品',
              '时间：2021-03-01',
              '地点：山赵村',
              '分配货车：鲁A00001',
            ],[
              '收货人：刘二',
              '联系方式：15552590009',
              '货物：冷藏食品',
              '时间：2021-03-01',
              '地点：赵家林',
              '分配货车：鲁A00001',
            ],
          ]
          break
        case '3':
          this.cards = [
            [
              '收货人：卜四',
              '联系方式：16776232970',
              '货物：化学药品',
              '时间：2021-03-01',
              '地点：西海岸汽车东站',
              '分配货车：闽D00003',
            ],
            [
              '收货人：李四',
              '联系方式：13864221722',
              '货物：化学药品',
              '时间：2021-03-01',
              '地点：庐山小区',
              '分配货车：闽D00003',
            ],
            [
              '收货人：刘三',
              '联系方式：13864221728',
              '货物：化学药品',
              '时间：2021-03-01',
              '地点：宝湾花园',
              '分配货车：闽D00003',
            ],
            [
              '收货人：赵三',
              '联系方式：18105421950',
              '货物：化学药品',
              '时间：2021-03-01',
              '地点：天智大厦',
              '分配货车：闽D00003',
            ],
            [
              '收货人：刘二',
              '联系方式：15552590009',
              '货物：化学药品',
              '时间：2021-03-01',
              '地点：安居小区(峨嵋山路)',
              '分配货车：闽D00003',
            ],
            [
              '收货人：朱三',
              '联系方式：18554943181',
              '货物：化学药品',
              '时间：2021-03-01',
              '地点：周家夼村',
              '分配货车：闽D00003',
            ]
          ]
          break
      }
    },
  },
}
</script>



<!-- <template>
  <div>
    <a-spin size="large" :spinning="spinning">
      <a-row :gutter="20">
        <a-col :span="24" class="item">
          <a-card hoverable class="add-item" @click="visible = true">
            <p class="ziti-1"> 路径规划</p>
            <div>
              <Mapview1/>
            </div>
          </a-card>
        </a-col>
      </a-row>
    </a-spin>
  </div>
</template>
<script>
import {FindAllVehicle, SaveVehicle} from "@/api/vehicle";
import * as echarts from 'echarts';
import Mapview1 from "../../components/Mapview1.vue";
export default {
  name: "WareHouse",
  components:{
    Mapview1
},
  data() {
    return {
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
    this.loadData()
  },
}
</script>
<style scoped>
*{
  margin: 0;
  padding: 0;
}
.add-item {
  text-align: center;
  line-height: 30px;
  height: 600px;
  border: 1px dashed #91949c;
  border-radius: 2%;
}
.add-item:hover {
  border: 1px dashed #5a84fd;
  color: #5a84fd;
}

.item {
  margin-bottom: 20px;
  border-radius: 1%;
}
.user {
    padding-bottom: 20px;
    display: flex;
    align-items: center; 
    margin: 0;
    padding: 0;
}
.ziti-1{
font-size: 30px;;
margin-left: 0px;
}
</style> -->