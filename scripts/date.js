import fs from "fs/promises";
import path from "path";

class DateInserter {
  constructor(config) {
    this.config = {
      files: ["history.md", "inbox.md"],
      dateFormat: "YYYY-MM-DD",
      ...config,
    };
  }

  async insertDate() {
    const today = new Date().toISOString().split("T")[0];
    const dateHeader = `\n# ${today}\n\n`;

    for (const file of this.config.files) {
      try {
        const filePath = path.join(process.cwd(), file);
        const content = await fs.readFile(filePath, "utf8");

        // 检查今天的日期是否已存在
        if (!content.includes(`# ${today}`)) {
          // 在文件开头插入新日期（在已有内容之前）
          const newContent = dateHeader + content;
          await fs.writeFile(filePath, newContent);
          console.log(`Successfully inserted date in ${file}`);
        }
      } catch (error) {
        console.error(`Error processing ${file}:`, error);
      }
    }
  }

  // 支持自定义日期格式
  formatDate(date, format = this.config.dateFormat) {
    return format
      .replace("YYYY", date.getFullYear())
      .replace("MM", String(date.getMonth() + 1).padStart(2, "0"))
      .replace("DD", String(date.getDate()).padStart(2, "0"));
  }
}

// 运行脚本
const inserter = new DateInserter({
  files: ["./active/history.md", "./active/inbox.md"],
  dateFormat: "YYYY-MM-DD",
});

inserter.insertDate().catch(console.error);
