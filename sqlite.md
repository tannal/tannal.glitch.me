

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