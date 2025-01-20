#let salary_table(data) = {
  // 表格样式
  set table(
    inset: 8pt,
    align: center,
    stroke: 0.7pt,
  )

  // 标题样式
  let header_style(content) = {
    set text(weight: "bold")
    content
  }

  // 金额格式化
  let format_money(amount) = {
    let num = str(amount)
    if "." not in num { num += ".00" }
    "¥" + num
  }

  // 创建表头
  table(
    columns: (auto, auto, auto, auto, auto, auto),
    align: (x, y) => if y == 0 { center } else { right },
    // 表头
    header_style[姓名], header_style[基本工资], header_style[绩效],
    header_style[补贴], header_style[扣除], header_style[实发工资],
    // 数据行
    ..data.map(row => (
      row.name,
      format_money(row.base),
      format_money(row.performance),
      format_money(row.allowance),
      format_money(row.deduction),
      format_money(row.base + row.performance + row.allowance - row.deduction)
    )).flatten()
  )
}

// 页面设置
#set page(
  paper: "a4",
  margin: (x: 2cm, y: 2cm),
)

// 标题
#align(center)[
  #text(size: 18pt, weight: "bold")[
    2024年1月工资表32321312
  ]
]

#v(1cm)

// 工资数据
#let salary_data = (
  (name: "张三", base: 8000, performance: 2000, allowance: 500, deduction: 1000),
  (name: "李四", base: 7500, performance: 1800, allowance: 400, deduction: 900),
  (name: "王五", base: 9000, performance: 2500, allowance: 600, deduction: 1200),
  (name: "赵六", base: 7000, performance: 1500, allowance: 300, deduction: 800),
)

// 生成表格
#salary_table(salary_data)

// 底部说明
#v(1cm)
#grid(
  columns: (1fr, 1fr),
  align: (left + bottom, right + bottom),
  [制表日期：2024年1月20日],
  [制表人：人力资源部]
)
