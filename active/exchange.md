# 2024 3-8

./pg_basebackup -h 192.168.43.246 -U replica -D data -X stream -P


创建流复制用户
启动数据库监听

CREATE ROLE replica REPLICATION LOGIN PASSWORD '123456';
data/pg_hba.con

# 允许从库通过replica用户连接主库
host   replication      replica       192.168.0.101/32          md

data/postgresql.conf

listen_addresses = '*' 
port = 5432
max_connections = 100 
max_wal_size = 1GB
min_wal_size = 80MB
log_timezone = 'Asia/Shanghai'
archive_mode = on
archive_command = 'test ! -f /var/lib/pgsql/13/archivelog/%f && cp %p /var/lib/pgsql/13/archivelog/%f'
wal_level = replica
max_wal_senders = 10
wal_sender_timeout = 60s

initdb -D $PGDATA -E UTF8 -k -U postgres -X /pg/pg_wal --wal-segsize=16

参数解释:
-D: 指定的默认数据库集簇的目录 
-E:数据库默认编码
-k: 启用页面校验（用于从节点流复制中的切换操作,pg_rewind）
-U:指定数据库的超级用户，如果不指定，默认以初始化执行的操作系统用户作为默认的超级用户
-X: 指定数据库 pg_wal 的日志目录
--wal-segsize: 指定单个 wal 段文件的大小，默认为16MB

# postgresql

sudo apt install flex bison

meson setup --reconfigure --prefix=/home/tannal/tannalwork/projects/postgres/_install build

ninja -C build

ninja install

export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/home/tannal/tannalwork/projects/postgres/_install/lib/

cd _install/bin

./initdb -d data



./postgres -D data/

vim data/postgresql.conf

pkill postgres
./pg_ctl -D data -l logfile start

vim data/postgresql.conf

listen-address

./psql -U tannal -w -d postgres
./psql -U tannal -w -d exchange

./psql -U -c 'create database exchange;'


CREATE TABLE chat (
  id INT serial primary KEY,
  query TEXT,
  answer TEXT
);
DROP TABLE tblname;
createdb exchage
select exchage

CREATE TABLE chat (
  id SERIAL PRIMARY KEY,
  query TEXT,
  answer TEXT
);

\list

sudo apt install inotify-tools

while inotifywait -e close_write server.go; do ./server.go; done


SELECT * FROM chat
WHERE query LIKE '%the%'
OR answer LIKE '%the%';

SELECT * FROM chat
WHERE query LIKE '%How%'
OR answer LIKE '%How%';


SELECT * FROM chat
WHERE query ILIKE '%postgresql%'
OR answer ILIKE '%postgresql%';

INSERT INTO chat (query, answer) VALUES
('How to write unit tests in JavaScript?', 'When writing unit tests in JavaScript, one can use frameworks like Jest or Mocha...'),
('Best practices for REST API design?', 'REST API design best practices include using HTTP methods explicitly, handling errors with HTTP status codes...'),
('Advantages of TypeScript over JavaScript?', 'TypeScript provides static typing, which can help catch errors early in the development process...'),
('How to improve SQL query performance?', 'To improve SQL query performance, one can use indexing, avoid SELECT *, and write efficient JOINs...'),
('Ways to prevent XSS attacks?', 'Preventing XSS attacks can be achieved by sanitizing user input, using Content Security Policy (CSP), and validating on the server-side...');


sudo tcpdump -i any -A -vv tcp port 8080

sudo tcpdump -i any -A -vv 'tcp port 5432 and (src host 192.168.43.27 or dst host 192.168.43.27)'


\password tannal

```go

package main

import (
	"database/sql"
	"encoding/json"
	"fmt"
	"io"
	"log"
	"net/http"
	"strings"

	_ "github.com/lib/pq"
)

const (
	dbConnectionString = "postgres://tannal:password@192.168.43.246:5432/exchange?sslmode=disable"
)

type RequestData struct {
	Query  string `json:"query"`
	Answer string `json:"answer"`
}

func insertData(db *sql.DB, query string, answer string) error {
	// Construct the SQL statement
	stmt := `INSERT INTO chat (query, answer) VALUES ($1, $2)`
	// Execute the SQL statement
	_, err := db.Exec(stmt, query, answer)
	return err
}

func searchHandler(db *sql.DB) http.HandlerFunc {
	return func(w http.ResponseWriter, r *http.Request) {
		// Set CORS headers for the preflight request
		if r.Method == http.MethodOptions {
			w.Header().Set("Access-Control-Allow-Origin", "*")
			w.Header().Set("Access-Control-Allow-Methods", "GET")
			w.WriteHeader(http.StatusOK)
			return
		}

		// Set CORS headers for the main request
		w.Header().Set("Access-Control-Allow-Origin", "*")

		// parse the url parameters
		query := r.URL.Query().Get("query")

		// search data from the database
		// SELECT * FROM chat WHERE query LIKE '%the%' OR answer LIKE '%the%';
		// rows, err := db.Query("SELECT query, answer FROM chat WHERE query iLIKE $1 OR answer iLIKE $2", "%"+query+"%", "%"+query+"%")

		// split the query with %20 ' '
		// then create a query with the split words
		keywords := strings.Split(query, " ")

		// log
		// fmt.Println(keywords)

		for i := 0; i < len(keywords); i++ {

			rows, err := db.Query("SELECT query, answer FROM chat WHERE query iLIKE $1 OR answer iLIKE $2", "%"+keywords[i]+"%", "%"+keywords[i]+"%")
			if err != nil {
				http.Error(w, err.Error(), http.StatusInternalServerError)
				return
			}
			for rows.Next() {
				var query string
				var answer string
				rows.Scan(&query, &answer)
				fmt.Fprintln(w, "Q:"+query)
				fmt.Fprintln(w, "A:"+answer)
			}
		}
		w.WriteHeader(http.StatusCreated)

		// for rows.Next() {
		// 	var query string
		// 	var answer string
		// 	rows.Scan(&query, &answer)
		// 	fmt.Fprintln(w, query, answer)
		// }
		// fmt.Fprintln(w, rows)
	}
}

func postHandler(db *sql.DB) http.HandlerFunc {
	return func(w http.ResponseWriter, r *http.Request) {
		// Set CORS headers for the preflight request
		if r.Method == http.MethodOptions {
			w.Header().Set("Access-Control-Allow-Origin", "*")
			w.Header().Set("Access-Control-Allow-Methods", "POST")
			w.Header().Set("Access-Control-Allow-Headers", "Content-Type")
			w.WriteHeader(http.StatusOK)
			return
		}

		// Set CORS headers for the main request
		w.Header().Set("Access-Control-Allow-Origin", "*")

		// Parse the request data
		var data RequestData
		err := json.NewDecoder(r.Body).Decode(&data)
		if err != nil {
			http.Error(w, err.Error(), http.StatusBadRequest)
			return
		}

		// Insert the data into the database
		if err := insertData(db, data.Query, data.Answer); err != nil {
			http.Error(w, err.Error(), http.StatusInternalServerError)
			return
		}

		// Send a success response
		w.WriteHeader(http.StatusCreated)
		fmt.Fprintln(w, "Data inserted successfully")
	}
}

func shareHandler(db *sql.DB) http.HandlerFunc {
	return func(w http.ResponseWriter, r *http.Request) {
		// Set CORS headers for the preflight request
		if r.Method == http.MethodOptions {
			w.Header().Set("Access-Control-Allow-Origin", "*")
			w.Header().Set("Access-Control-Allow-Methods", "GET")
			w.WriteHeader(http.StatusOK)
			return
		}

		// Set CORS headers for the main request
		w.Header().Set("Access-Control-Allow-Origin", "*")

		// get the share url from the request
		shareURL := r.URL.Query().Get("url")

		// Get the data from the OpenAI chat page
		client := &http.Client{}
		req, err := http.NewRequest("GET", shareURL, nil)
		if err != nil {
			log.Fatal(err)
		}
		resp, err := client.Do(req)
		if err != nil {
			log.Fatal(err)
		}
		defer resp.Body.Close()
		body, err := io.ReadAll(resp.Body)
		if err != nil {
			log.Fatal(err)
		}

		html := string(body)

		start := strings.LastIndex(html, ">{")

		end := strings.LastIndex(html, "}</script>")

		data := html[start+1 : end+1]

		var response Response
		err = json.Unmarshal([]byte(data), &response)
		if err != nil {
			panic(err)
		}

		var query string
		var answer string

		for i, linearConversation := range response.Props.PageProps.ServerResponse.Data.LinearConversation {
			for _, part := range response.Props.PageProps.ServerResponse.Data.Mapping[linearConversation.Id].Message.Content.Parts {
				if i%2 == 0 {
					query = part
				} else {
					answer = part
					fmt.Println(query, answer)
				}
			}
		}

		// Insert the data into the database
		if err := insertData(db, query, answer); err != nil {
			http.Error(w, err.Error(), http.StatusInternalServerError)
			return
		}

		// Send the data as the HTTP response
		w.Header().Set("Content-Type", "application/json")
		json.NewEncoder(w).Encode(data)
	}
}

func main() {
	// Connect to the PostgreSQL database
	db, err := sql.Open("postgres", dbConnectionString)
	if err != nil {
		log.Fatal(err)
	}
	defer db.Close()

	// Set up the HTTP handler for POST requests
	http.HandleFunc("/post", postHandler(db))

	http.HandleFunc("/search", searchHandler(db))

	http.HandleFunc("/share", shareHandler(db))

	// Start the HTTP server
	log.Fatal(http.ListenAndServe(":8080", nil))
}


```


```js

document.querySelectorAll('[data-message-id]').forEach(v => console.log(v.innerText))

```