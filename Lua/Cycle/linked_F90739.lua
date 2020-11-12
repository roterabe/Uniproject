function insertlist(h, x, b)
    local nlist = {}
    nlist = makelist(x)
    nlist.prev = h
    nlist.next = h.next
    h.next = nlist
    if b == true then
        return nlist
    else
        return h
    end
end

function printlist(list)
    local it = list
    repeat
        print(it.value)
        it = it.next
    until it == list
end

function makelist(val)
    local list = {}
    list.prev = list
    list.next = list
    list.value = val
    return list
end

function removelist(h, f, t)

end

local v = 10
local c = 20
local d = 30
list = {}
list.prev = list
list.next = list
list.value = v

list = insertlist(list, c, true)
list = insertlist(list, d, true)

printlist(list)

