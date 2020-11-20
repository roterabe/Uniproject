-- Прости действия с линеен, свързан списък.
-- Списъкът се образува от членове-таблици.
-- Всяка таблица – член на списък, има полета с имена
-- data (съдържание) и next (указател към следващия член)

-- отпечатване на съдържанието на списък
function printlist(p)
  while p~=nil do
    print(p.data)
    p = p.next
  end
end

-- обръщане на списък (без образуване на нови членове – сменят се само указателите)
function reverselist(p)
  local q = nil
  while p~=nil do
    local k = q
    q = p
    p = p.next
    q.next = k
  end
  return q
end

-- пример: образуване на списък чрез четене на стойности от стандартния вход
-- (списъкът се получава обърнат), показване на съдържанието, обръщане и
-- отново показване на съдържанието
p = nil
for s in io.lines("ex.txt") do
  p = {next = p, data = s}
end

print()
printlist(p)

p = reverselist(p)

print()
printlist(p)
print()