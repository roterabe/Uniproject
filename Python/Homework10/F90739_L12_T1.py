#!/usr/bin/env python3

import sqlite3
from sys import argv

query = ""
data = []
db = "f90739-food.db"


def create_connection(db_file):
    conn = None
    try:
        conn = sqlite3.connect(db_file)
    except sqlite3.Error as e:
        print(e)
        print("Unable to establish connection to database...\n")

    return conn


def insert_into(conn, data_field):
    sql = ''' INSERT or REPLACE INTO food(code,descript,nmbr,nutname,retention)
              VALUES(?,?,?,?,?) '''
    cur = conn.cursor()
    cur.execute(sql, (data_field[0], data_field[1],
                      data_field[2], data_field[3], data_field[4]))

"""
def clear_duplicates(conn):
    sql1 = ''' DELETE FROM food
WHERE rowid NOT in (select min(rowid)
                    FROM food
                    GROUP BY code, descript,nmbr) '''
    cur = conn.cursor()
    cur.execute(sql1)
"""

try:
    if len(argv) == 2:
        query = argv[1]
    else:
        raise
except:
    print("\nYou need to specify what you want to be called from the database!")
    print("Usage: \"F90739_L12_T1.py -query\" \n")

database = create_connection(db)

database.execute('''CREATE TABLE IF NOT EXISTS food
         (code VARCHAR(255),
         descript VARCHAR(255),
         nmbr INTEGER,
         nutname VARCHAR(255),
         retention INTEGER,
         UNIQUE(code, descript,nmbr))''')

database.commit()


with open('retn5_dat.txt', 'r') as rfile:
    lines = rfile.read().splitlines()
    data = [line.replace('~', '').split('^') for line in lines]
# print(data)

with database:
    for data_field in data:
        insert_into(database, data_field)
"""
with database:
    clear_duplicates(database)
"""

cur = database.cursor()
cur.execute(query)
try:
    result = cur.fetchone()
    if (result != None):
        print(str(result))
    else:
        raise
except:
    print("\nThe information is either missing or your query is not valid!\n")

cur.close()
