function Reverselist(p)
    local q = nil
    while p do
      local k = q
      q = p
      p = p.next
      q.next = k
    end
    return q
end

function Last (list)
  -- Just checking...
  if list == nil then
    return nil
  end

  -- We start at the first node...
  local node = list
  -- ...while there's a next...
  while node.next ~= nil do
    -- ... we move to it
    node = node.next
  end
  -- when we reach this line, node variable holds the
  -- last element in the list
  return node
end


function Looplist(p)
  local temp = p
  p = Last(p)
  p.next = temp
  return p
end

function Printer(p)
  local l = p
  while l do
      print(l.value)
      l = l.next
  end
end

list = nil
local v = 10
local c = 20
local d = 30
list = {next = list, value = v}
list = {next = list, value = c}
list = {next = list, value = d}

list = Looplist(list)
Printer(list)

