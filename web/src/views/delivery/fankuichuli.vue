<template>
  <div>
    <a-card style="border: 0px;box-shadow: 0 3px 8px 0 rgba(0, 0, 0, 0.1);border-radius: 30px;" class="shouye">
      <a-table bordered :data-source="dataSource" :columns="columns">
        <template slot="name" slot-scope="text, record">
          <editable-cell :text="text" @change="onCellChange(record.key, 'name', $event)" />
        </template>
        <template slot="operation" slot-scope="text, record">
          <a-popconfirm v-if="dataSource.length" title="Sure to delete?" @confirm="() => onDelete(record.key)">
            <a href="javascript:;">删除</a>
          </a-popconfirm>
        </template>
      </a-table>
    </a-card>
  </div>
</template>
<script>
const EditableCell = {
  template: `
      <div class="editable-cell">
        <div v-if="editable" class="editable-cell-input-wrapper">
          <a-input :value="value" @change="handleChange" @pressEnter="check" /><a-icon
            type="check"
            class="editable-cell-icon-check"
            @click="check"
          />
        </div>
        <div v-else class="editable-cell-text-wrapper">
          {{ value || ' ' }}
          <a-icon type="edit" class="editable-cell-icon" @click="edit" />
        </div>
      </div>
    `,
  props: {
    text: String,
  },
  data() {
    return {
      value: this.text,
      editable: false,
    };
  },
  methods: {
    handleChange(e) {
      const value = e.target.value;
      this.value = value;
    },
    check() {
      this.editable = false;
      this.$emit('change', this.value);
    },
    edit() {
      this.editable = true;
    },
  },
};
export default {
  components: {
    EditableCell,
  },
  data() {
    return {
      dataSource: [
        {
          key: '0',
          name: '2023-04-06',
          age: '李四',
          tags: '已处理',
          address: '行驶中，疲劳提醒功能无法使用。',
        },
        {
          key: '0',
          name: '2023-04-03',
          age: '朱三',
          tags: '已处理',
          address: '刷卡失败，需要补办。',
        },
        {
          key: '0',
          name: '2023-04-01',
          age: '张六',
          tags: '已处理',
          address: '车辆启动时，发现启动困难，需要修理。',
        },
        {
          key: '0',
          name: '2023-03-29',
          age: '王五',
          tags: '已处理',
          address: '后视镜视线不良，需要调整或更换。',
        },
        {
          key: '1',
          name: '2023-03-25',
          age: '刘二',
          tags: '已处理',
          address: '希望快速折叠座椅和放平座椅的操作更便捷。',
        },
        {
          key: '2',
          name: '2023-03-22',
          age: '赵三',
          tags: '已处理',
          address: '希望车载充电口能够支持USB接口。',
        },
        {
          key: '3',
          name: '2023-03-13',
          age: '王五',
          tags: '已处理',
          address: '车辆加速时，发现有顿挫现象。',
        },
        {
          key: '3',
          name: '2023-03-10',
          age: '刘三',
          tags: '已处理',
          address: '车窗不易上下，请检查电动窗系统。',
        },
        {
          key: '3',
          name: '2023-03-06',
          age: '赵三',
          tags: '已处理',
          address: '刹车时有异响，请检查制动系统。',
        },
        {
          key: '3',
          name: '2023-03-03',
          age: '张六',
          tags: '已处理',
          address: '车内音响声音过小，请检查音响系统。',
        },
        {
          key: '3',
          name: '2023-03-01',
          age: '李五',
          tags: '已处理',
          address: '希望车内空调能够调节风向和风量。',
        },
        {
          key: '3',
          name: '2023-02-28',
          age: '王二',
          tags: '已处理',
          address: '行驶时导航不准确，请及时更新地图。',
        },

      ],
      count: 2,
      columns: [
        {
          title: '时间',
          dataIndex: 'name',
          // scopedSlots: { customRender: 'name' },
        },
        {
          title: '用户名',
          dataIndex: 'age',
        },
        {
          title: '反馈内容',
          dataIndex: 'address',
        },
        {
          title: '处理状态',
          key: 'tags',
          dataIndex: 'tags',
          scopedSlots: { customRender: 'tags' },
        },
        {
          title: '操作',
          dataIndex: 'operation',
          scopedSlots: { customRender: 'operation' },
        },
      ],
    };
  },
  methods: {
    onCellChange(key, dataIndex, value) {
      const dataSource = [...this.dataSource];
      const target = dataSource.find(item => item.key === key);
      if (target) {
        target[dataIndex] = value;
        this.dataSource = dataSource;
      }
    },
    onDelete(key) {
      const dataSource = [...this.dataSource];
      this.dataSource = dataSource.filter(item => item.key !== key);
    },
    handleAdd() {
      const { count, dataSource } = this;
      const newData = {
        key: count,
        name: `Edward King ${count}`,
        age: 32,
        address: `London, Park Lane no. ${count}`,
      };
      this.dataSource = [...dataSource, newData];
      this.count = count + 1;
    },
  },
};
</script>
<style>
.editable-cell {
  position: relative;
}

.editable-cell-input-wrapper,
.editable-cell-text-wrapper {
  padding-right: 24px;
}

.editable-cell-text-wrapper {
  padding: 5px 24px 5px 5px;
}

.editable-cell-icon,
.editable-cell-icon-check {
  position: absolute;
  right: 0;
  width: 20px;
  cursor: pointer;
}

.editable-cell-icon {
  line-height: 18px;
  display: none;
}

.editable-cell-icon-check {
  line-height: 28px;
}

.editable-cell:hover .editable-cell-icon {
  display: inline-block;
}

.editable-cell-icon:hover,
.editable-cell-icon-check:hover {
  color: #108ee9;
}

.editable-add-btn {
  margin-bottom: 8px;
}
</style>