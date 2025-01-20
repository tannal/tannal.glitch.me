// === 常量定义 ===
#let WEEKEND_RATE = 2.0     // 周末加班倍率
#let HOLIDAY_RATE = 3.0     // 节假日加班倍率
#let NORMAL_HOURS = 8       // 正常工作时长
#let MONTH_DAYS = 21.75     // 月标准工作日
#let SOCIAL_INSURANCE = 0.105 // 社保费率
#let HOUSE_FUND = 0.07      // 公积金费率
#let TAX_THRESHOLD = 5000   // 个税起征点

// === 工资计算函数 ===
#let calculate_overtime(base_salary, hours, rate) = {
  // 加班费 = 基本时薪 × 加班时长 × 倍率
  let base_hourly = base_salary / (MONTH_DAYS * NORMAL_HOURS)
  hours * base_hourly * rate
}

#let calculate_piece_wage(pieces, unit_price) = {
  // 计件工资 = 件数 × 单价
  pieces * unit_price
}

#let calculate_deductions(base, performance) = {
  // 社保
  let social = base * SOCIAL_INSURANCE
  // 公积金
  let house = base * HOUSE_FUND
  // 个税(简化版)
  let taxable = base + performance - social - house - TAX_THRESHOLD
  let tax = if taxable <= 0 { 0 } else { taxable * 0.03 }

  (social: social, house: house, tax: tax)
}

// === 表格生成函数 ===
#let create_salary_table(data) = {
  // 表格样式设置
  set table(
    inset: 6pt,
    align: center,
    stroke: 0.7pt,
    row-gutter: 3pt
  )

  // 表头样式
  let th(content) = {
    set text(weight: "bold", size: 9pt)
    content
  }

  // 数字格式化
  let fmt_num(num, decimals: 2) = {
    let s = str(calc.round(num, digits: decimals))
    if "." not in s { s += ".00" }
    s
  }

  // 金额格式化
  let fmt_money(amount) = {
    "¥" + fmt_num(amount)
  }

  table(
    columns: (auto, auto, auto, auto, auto, auto, auto, auto, auto, auto, auto, auto),
    align: (x, y) => if y == 0 { center } else { right },
    // 表头
    th[姓名], th[基本工资], th[出勤天数], th[请假天数],
    th[周末加班(h)], th[节假日加班(h)], th[计件数],
    th[绩效], th[应发工资], th[社保公积金], th[个税], th[实发工资],
    // 数据行
    ..data.map(row => {
      // 计算加班费
      let weekend_pay = calculate_overtime(row.base_salary, row.weekend_hours, WEEKEND_RATE)
      let holiday_pay = calculate_overtime(row.base_salary, row.holiday_hours, HOLIDAY_RATE)

      // 计算计件工资
      let piece_pay = calculate_piece_wage(row.pieces, row.piece_price)

      // 计算应发工资
      let total_pay = row.base_salary + weekend_pay + holiday_pay + piece_pay + row.performance

      // 计算扣除项
      let deductions = calculate_deductions(row.base_salary, row.performance)

      // 计算实发工资
      let net_pay = total_pay - deductions.social - deductions.house - deductions.tax

      // 返回行数据
      (
        row.name,
        fmt_money(row.base_salary),
        fmt_num(row.work_days, decimals: 1),
        fmt_num(row.leave_days, decimals: 1),
        fmt_num(row.weekend_hours, decimals: 1),
        fmt_num(row.holiday_hours, decimals: 1),
        str(row.pieces),
        fmt_money(row.performance),
        fmt_money(total_pay),
        fmt_money(deductions.social + deductions.house),
        fmt_money(deductions.tax),
        fmt_money(net_pay)
      )
    }).flatten()
  )
}

// === 页面设置 ===
#set page(
  paper: "a4",
  margin: (x: 1.5cm, y: 2cm),
  header: align(center)[
    #text(weight: "bold")[某某公司]
    #v(3pt)
    #line(length: 100%)
  ],
  footer: [
    #align(center)[
      第 #counter(page).display() 页
    ]
  ]
)

// === 标题 ===
#align(center)[
  #text(size: 16pt, weight: "bold")[
    2024年1月工资表
  ]
]

#v(0.8cm)

// === 示例数据 ===
#let salary_data = (
  (
    name: "张三",
    base_salary: 8000,
    work_days: 20,
    leave_days: 1.5,
    weekend_hours: 16,
    holiday_hours: 8,
    pieces: 150,
    piece_price: 5,
    performance: 2000
  ),
  (
    name: "李四",
    base_salary: 7500,
    work_days: 21.75,
    leave_days: 0,
    weekend_hours: 24,
    holiday_hours: 0,
    pieces: 200,
    piece_price: 4.5,
    performance: 1800
  ),
    (
    name: "王五",
    base_salary: 9000,
    work_days: 21,
    leave_days: 0.5,
    weekend_hours: 12,
    holiday_hours: 16,
    pieces: 180,
    piece_price: 5.5,
    performance: 2500
  )
)

// === 生成工资表 ===
#create_salary_table(salary_data)

// === 底部说明 ===
#v(1cm)
#grid(
  columns: (1fr, 1fr, 1fr),
  gutter: 1em,
  [
    *制表说明：*
    1. 工资计算期间：2024年1月1日至1月31日
    2. 基本工资按出勤天数比例计算
    3. 加班费：周末2倍，节假日3倍
    4. 社保及公积金按国家规定比例扣除
    5. 个人所得税按最新税率表计算
  ],
  [
    *备注：*
    - 请假包含事假、病假等
    - 加班时间已经部门领导确认
    - 计件工资按当月实际完成数计算
  ],
  [
    制表日期：2024年1月20日
    #v(8pt)
    制表人：#box(width: 80pt, stroke: (bottom: 0.5pt))[人力资源部]
    #v(8pt)
    部门负责人：#box(width: 80pt, stroke: (bottom: 0.5pt))[]
  ]
)
