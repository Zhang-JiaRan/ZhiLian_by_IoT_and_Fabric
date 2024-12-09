
<template>
  <a-card style="border: 0px;box-shadow: 0 3px 8px 0 rgba(0, 0, 0, 0.1);border-radius: 30px;" class="shouye">
    <div>
      <a-row style="min-height: 0.9rem; font-size: 0.4rem;">
        <a-col :span="6">
          <!-- <a-input-search v-if="searchName != '9'" placeholder="输入记录号" enter-button v-model="searchName"
            @search="onSearch" /> -->
          <a-input-search placeholder="输入记录号" enter-button v-model="searchName" @search="onSearch" />
        </a-col>
      </a-row>
      <a-table  :columns="columns" :data-source="datalt" bordered style="margin-top: 20px;">
        <template slot="name" slot-scope="text">
          <a>{{ text }}</a>
        </template>
      </a-table>
      <!-- <a-table v-else :columns="columns1" :data-source="datalt1" bordered style="margin-top: 20px;">
        <template slot="name" slot-scope="text">
          <a>{{ text }}</a>
        </template>
      </a-table> -->
    </div>
  </a-card>
</template>

<script>
const data = [
  {
    record: '8',
    driver: '刘三',
    car: '鲁B00003',
    arrivaltime: '2023.03.08',
    phone: '13864221728',
    address: '山东省青岛市黄岛区长江西路努力66号',
    hash: '5BA42E08D6F175BADE9A9AAE50E24DCFAED60E45DBDBC2AD716A5D6CEC2D99E2'
  },
  {
    record: '7',
    driver: '李四',
    car: '鲁B00001',
    arrivaltime: '2023.03.07',
    phone: '13864221722',
    address: '山东省青岛市黄岛区长江西路努力66号',
    hash: '85BC2392CD77F5FFF5F169C499E3B394DD48EC885C02FA4B1E92D2285D20160B'
  },
  {
    record: '6',
    driver: '王二',
    car: '鲁A00003',
    arrivaltime: '2023.03.05',
    phone: '17753840238',
    address: '山东省青岛市黄岛区长江西路努力66号',
    hash: 'A860A8E71B4D3EA460FA6C368C0364EBAAACE37D5A60224CAE4CD1E6E2396743'
  },
  {
    record: '5',
    driver: '王五',
    car: '闽A00003',
    arrivaltime: '2023.03.03',
    phone: '13864292722',
    address: '山东省青岛市黄岛区长江西路努力66号',
    hash: 'D268DC62687B140625FCE1756E56FFCC6902C1F5E9260BC015A91729C4998C44'
  },
  {
    record: '4',
    driver: '赵三',
    car: '闽A00002',
    arrivaltime: '2023.03.03',
    phone: '18105421950',
    address: '山东省青岛市黄岛区长江西路努力66号',
    hash: '53BB6D3BABC64EBB948A4D8F3C4EED9E057FC3166CBB7A389CD3CB8328A3CC5F'
  },
  {
    record: '3',
    driver: '刘二',
    car: '闽D00002',
    arrivaltime: '2023.03.02',
    phone: '15552590009',
    address: '山东省青岛市黄岛区长江西路努力66号',
    hash: 'C2A181D8178A9F753B013FC4BB892CEEB5DC5BCB763352610844B93341EA52A4'
  },
  {
    record: '2',
    driver: '张六',
    car: '闽D00003',
    arrivaltime: '2023.02.29',
    phone: '13864292022',
    address: '山东省青岛市黄岛区长江西路努力66号',
    hash: '96061E92F58E4BDCDEE73DF36183FE3AC64747C81C26F6C83AADA8D2AABB1864'
  },
  {
    record: '1',
    driver: '李四',
    car: '鲁B00001',
    arrivaltime: '2023.02.24',
    phone: '13864221722',
    address: '山东省青岛市黄岛区长江西路努力66号',
    hash: '7902699BE42C8A8E46FBBB4501726517E86B22C56A189F7625A6DA49081B2451'
  },
  {
    record: '0',
    driver: '万三',
    car: '鲁A00002',
    arrivaltime: '2023.02.26',
    phone: '13864221728',
    address: '山东省青岛市黄岛区长江西路努力66号',
    hash: '4B227777D4DD1FC61C6F884F48641D02B4D121D3FD328CB08B5531FCACDABF8A'
  },
]

// const data1 = [
//   {
//     record: '8',
//     driver: '刘三',
//     car: '鲁B00003',
//     arrivaltime: '2023.03.08',
//     phone: '13864221728',
//     address: '山东省青岛市黄岛区长江西路努力66号',
//     hash: '5BA42E08D6F175BADE9A9AAE50E24DCFAED60E45DBDBC2AD716A5D6CEC2D99E2'
//   },
//   {
//     record: '7',
//     driver: '李四',
//     car: '鲁B00001',
//     arrivaltime: '2023.03.07',
//     phone: '13864221722',
//     address: '山东省青岛市黄岛区长江西路努力66号',
//     hash: '85BC2392CD77F5FFF5F169C499E3B394DD48EC885C02FA4B1E92D2285D20160B'
//   },
//   {
//     record: '6',
//     driver: '王二',
//     car: '鲁A00003',
//     arrivaltime: '2023.03.05',
//     phone: '17753840238',
//     address: '山东省青岛市黄岛区长江西路努力66号',
//     hash: 'A860A8E71B4D3EA460FA6C368C0364EBAAACE37D5A60224CAE4CD1E6E2396743'
//   },
//   {
//     record: '5',
//     driver: '王五',
//     car: '闽A00003',
//     arrivaltime: '2023.03.03',
//     phone: '13864292722',
//     address: '山东省青岛市黄岛区长江西路努力66号',
//     hash: 'D268DC62687B140625FCE1756E56FFCC6902C1F5E9260BC015A91729C4998C44'
//   },
//   {
//     record: '4',
//     driver: '赵三',
//     car: '闽A00002',
//     arrivaltime: '2023.03.03',
//     phone: '18105421950',
//     address: '山东省青岛市黄岛区长江西路努力66号',
//     hash: '53BB6D3BABC64EBB948A4D8F3C4EED9E057FC3166CBB7A389CD3CB8328A3CC5F'
//   },
//   {
//     record: '3',
//     driver: '刘二',
//     car: '闽D00002',
//     arrivaltime: '2023.03.02',
//     phone: '15552590009',
//     address: '山东省青岛市黄岛区长江西路努力66号',
//     hash: 'C2A181D8178A9F753B013FC4BB892CEEB5DC5BCB763352610844B93341EA52A4'
//   },
//   {
//     record: '2',
//     driver: '张六',
//     car: '闽D00003',
//     arrivaltime: '2023.02.29',
//     phone: '13864292022',
//     address: '山东省青岛市黄岛区长江西路努力66号',
//     hash: '96061E92F58E4BDCDEE73DF36183FE3AC64747C81C26F6C83AADA8D2AABB1864'
//   },
//   {
//     record: '1',
//     driver: '李四',
//     car: '鲁B00001',
//     arrivaltime: '2023.02.24',
//     phone: '13864221722',
//     address: '山东省青岛市黄岛区长江西路努力66号',
//     hash: '7902699BE42C8A8E46FBBB4501726517E86B22C56A189F7625A6DA49081B2451'
//   },
//   {
//     record: '0',
//     driver: '万三',
//     car: '鲁A00002',
//     arrivaltime: '2023.02.26',
//     phone: '13864221728',
//     address: '山东省青岛市黄岛区长江西路努力66号',
//     hash: '4B227777D4DD1FC61C6F884F48641D02B4D121D3FD328CB08B5531FCACDABF8A'
//   },
// ]

// 在data中定义searchName模糊搜索双向模型 ，columns 定义表格头部信息，data：表格数据信息，datalt过滤后展示的表格数据列表
export default {
  name: 'projectName',
  data() {
    return {
      searchName: '',
      columns: [
        {
          title: '记录号',
          dataIndex: 'record',
          scopedSlots: { customRender: 'record' },
          filteredValue: this.searchName ? this.searchName : null,
        },
        {
          title: '司机',
          className: 'column-driver',
          dataIndex: 'driver',
        },
        {
          title: '货车',
          dataIndex: 'car',
        },
        {
          title: '到达时间',
          dataIndex: 'arrivaltime',
        },
        {
          title: '司机电话',
          dataIndex: 'phone',
        },
        {
          title: '地址',
          dataIndex: 'address',
        },
        {
          title: '区块哈希值',
          dataIndex: 'hash',
        },
      ],
      data,
      datalt: data,
      // columns1: [
      //   {
      //     title: '记录号',
      //     dataIndex: 'record',
      //     scopedSlots: { customRender: 'record' },
      //     filteredValue: this.searchName ? this.searchName : null,
      //   },
      //   {
      //     title: '司机',
      //     className: 'column-driver',
      //     dataIndex: 'driver',
      //   },
      //   {
      //     title: '货车',
      //     dataIndex: 'car',
      //   },
      //   {
      //     title: '到达时间',
      //     dataIndex: 'arrivaltime',
      //   },
      //   {
      //     title: '司机电话',
      //     dataIndex: 'phone',
      //   },
      //   {
      //     title: '地址',
      //     dataIndex: 'address',
      //   },
      //   {
      //     title: '区块哈希值',
      //     dataIndex: 'hash',
      //   },
      // ],
      // data1,
      // datalt1: data1,
    }
  },
  methods: {
    // onSearch 搜索功能，根据输入框中输入的字符进行在数组中过滤更新到新的数组中并在前端页面渲染展示
    onSearch() {
      if (this.searchName=='9'){
        const newData = {
        record: '9',
        driver: '李四',
        car: '鲁A00003',
        arrivaltime: '2023.03.10',
        phone: '13864221728',
        address: '山东省青岛市黄岛区长江西路努力66号',
        hash: '77BAA8EEF581031F8EBD583029C23E0CADD006948143FE061BEA57B58FA1E72D'
      };

      this.data.unshift(newData);
      }
      if (this.searchName && this.searchName !== '') {
        this.datalt = this.data.filter(
          (p) => p.record.indexOf(this.searchName) !== -1
        )
      } else {
        this.datalt = this.data
      }

    },
    onSearch1() {
      const newData = {
        record: '9',
        driver: '李四',
        car: '鲁A00003',
        arrivaltime: '2023.03.10',
        phone: '13864221728',
        address: '山东省青岛市黄岛区长江西路努力66号',
        hash: '77BAA8EEF581031F8EBD583029C23E0CADD006948143FE061BEA57B58FA1E72D'
      };

      this.data1.unshift(newData);
      if (this.searchName && this.searchName !== '') {
        this.datalt1 = this.data1.filter((p) => p.record.indexOf(this.searchName) !== -1);
      } else {
        this.datalt1 = this.data1;
      }

      
    },
  },
}
</script>
