// 50 / 51 个通过测试用例
// Line 28: RangeError: Maximum call stack size exceeded
// TODO::使用线段树,将没有经过查询的节点,不必计算发钱的数量.
/**
 * @param {number} n
 * @param {number[][]} leadership
 * @param {number[][]} operations
 * @return {number[]}
 */
var bonus = function(n, leadership, operations) {
  var team = {},
    result = [];
  // 构建关系表
  for (let item of leadership) {
    // 领导
    team[item[0]] = team[item[0]] || {
      own: 0,
      sum: 0,
      leader: null,
      member: []
    };
    // 下属
    team[item[1]] = team[item[1]] || {
      own: 0,
      sum: 0,
      leader: null,
      member: []
    };
    team[item[0]].member.push(team[item[1]]);
    team[item[1]].leader = team[item[0]];
  }
  let memberAddBonus = (mem, bonus) => {
    mem.own += bonus;
    let memAddition = 0;
    if (mem.member.length > 0) memAddition = mem.member.map(curmem => memberAddBonus(curmem, bonus)).reduce((pre, cur) => pre + cur);
    mem.sum += memAddition + bonus;
    return memAddition + bonus;
  };
  let leaderAddBonus = (leader, bonus) => {
    while (leader != null) {
      leader.sum += bonus;
      leader = leader.leader;
    }
  };
  // 进行操作
  for (let operate of operations) {
    let bonus = operate[2] || 0,
      ptr = team[operate[1]];
    switch (operate[0]) {
      case 1:
        ptr.own += bonus;
        ptr.sum += bonus;
        leaderAddBonus(ptr.leader, bonus);
        break;
      case 2:
        let additional = memberAddBonus(ptr, bonus);
        leaderAddBonus(ptr.leader, additional);
        break;
      case 3:
        result.push(team[operate[1]].sum % 100000007);
        break;
    }
  }
  return result;
};
