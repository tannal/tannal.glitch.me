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
    "log"
    "net/http"

    _ "github.com/lib/pq"
)

const (
    dbConnectionString = "postgres://tannal:password@localhost:5432/exchange?sslmode=disable"
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

func main() {
    // Connect to the PostgreSQL database
    db, err := sql.Open("postgres", dbConnectionString)
    if err != nil {
        log.Fatal(err)
    }
    defer db.Close()

    // Set up the HTTP handler for POST requests
    http.HandleFunc("/post", postHandler(db))

    // Start the HTTP server
    log.Fatal(http.ListenAndServe(":8080", nil))
}


```


```js

document.querySelectorAll('[data-message-id]').forEach(v => console.log(v.innerText))

```