
您说得对，Firefox、Chrome 和 Edge 的浏览记录都是使用 SQLite3 数据库存储的。以下是这些浏览器在 Ubuntu 和 Windows 系统下存储历史记录的典型路径：

Ubuntu:

1. Firefox:
   ~/.mozilla/firefox/[profile_folder]/places.sqlite

2. Chrome:
   ~/.config/google-chrome/Default/History

3. Edge:
   ~/.config/microsoft-edge/Default/History

Windows:

1. Firefox:
   C:\Users\[Username]\AppData\Roaming\Mozilla\Firefox\Profiles\[profile_folder]\places.sqlite

2. Chrome:
   C:\Users\[Username]\AppData\Local\Google\Chrome\User Data\Default\History

3. Edge:
   C:\Users\[Username]\AppData\Local\Microsoft\Edge\User Data\Default\History

注意事项：

1. 在这些路径中，[Username] 应替换为实际的用户名，[profile_folder] 是一个随机生成的字符串，代表特定的 Firefox 配置文件。

2. 如果使用了多个配置文件，可能会有多个类似的文件夹。

3. 在访问这些文件时，最好先关闭相应的浏览器，因为浏览器运行时可能会锁定这些文件。

4. 路径可能会因浏览器版本或特定的安装选项而略有不同。

5. 在 Ubuntu 中，"~" 表示用户的主目录。

6. 在 Windows 中，AppData 文件夹默认是隐藏的，您可能需要在文件资源管理器中启用"显示隐藏的文件和文件夹"选项。

如果您需要查询或分析这些 SQLite 数据库，可以使用 SQLite 命令行工具或各种 SQLite 图形界面工具。请记住，直接修改这些文件可能会影响浏览器的正常运行，因此在进行任何操作之前，最好先备份这些文件。

# dev

```bash
https://github.com/sqlite/sqlite.git
./configure --prefix=/opt/sqlite
make -j20
```


1. Firefox (places.sqlite):

```sql
sqlite3 places.sqlite

-- 查询最近的 50 条访问记录
SELECT datetime(moz_historyvisits.visit_date/1000000, 'unixepoch', 'localtime') AS visit_time,
       moz_places.url, moz_places.title
FROM moz_places, moz_historyvisits
WHERE moz_places.id = moz_historyvisits.place_id
ORDER BY visit_time DESC
LIMIT 50;
```

2. Chrome/Edge (History):

```sql
sqlite3 History

-- 查询最近的 50 条访问记录
SELECT datetime(last_visit_time/1000000-11644473600, 'unixepoch', 'localtime') AS visit_time,
       url, title
FROM urls
ORDER BY last_visit_time DESC
LIMIT 50;
```

一些通用的 SQLite 命令和技巧：

1. 列出所有表：
   ```
   .tables
   ```

2. 显示表结构：
   ```
   .schema table_name
   ```

3. 设置输出模式为列表：
   ```
   .mode column
   .headers on
   ```

4. 导出查询结果到文件：
   ```
   .output results.txt
   -- 运行您的查询
   .output stdout
   ```

5. 按日期范围查询：
   ```sql
   -- Chrome/Edge 示例
   SELECT datetime(last_visit_time/1000000-11644473600, 'unixepoch', 'localtime') AS visit_time,
          url, title
   FROM urls
   WHERE visit_time BETWEEN '2023-01-01' AND '2023-12-31'
   ORDER BY visit_time DESC;
   ```

6. 查找最常访问的网站：
   ```sql
   -- Chrome/Edge 示例
   SELECT url, title, visit_count
   FROM urls
   ORDER BY visit_count DESC
   LIMIT 10;
   ```

7. 搜索特定关键词：
   ```sql
   -- Chrome/Edge 示例
   SELECT datetime(last_visit_time/1000000-11644473600, 'unixepoch', 'localtime') AS visit_time,
          url, title
   FROM urls
   WHERE title LIKE '%搜索关键词%' OR url LIKE '%搜索关键词%'
   ORDER BY visit_time DESC;
   ```

请注意，这些查询可能需要根据具体的数据库结构进行调整。在使用之前，建议先检查表结构（使用 .schema 命令）以确保字段名称正确。

另外，请记住在查询这些数据库时要遵守隐私和法律规定。如果您在查询他人的浏览历史，确保您有适当的权限这样做。