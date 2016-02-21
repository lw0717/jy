// yizhi-chan.c һָ��

inherit SKILL;

mapping *action = ({
([	"action" : "$N˫ָ��£��һʽ��������������������ϣ�������һǰһ�����$n���ظ���",
	"force" : 60,
        "dodge" : -5,
        "parry" : -5,
	"damage": 10,
	"lvl" : 0,
	"skill_name" : "�������",
	"damage_type" : "����"
]),
([	"action" : "$N���ƻ��أ�һʽ��������ա���������ָǰ���˸��뻡���͵�һ˦������$n��$l",
	"force" : 120,
        "dodge" : 10,
        "parry" : 15,
	"damage": 30,
	"lvl" : 20,
	"skill_name" : "�������",
        "damage_type" : "����"
]),
([	"action" : "$N����������һʽ�����Ź�ɡ���˫��ʳָ�˲������һ������������$n��ȫ��ҪѨ",
	"force" : 240,
        "dodge" : 20,
        "parry" : 20,
	"damage": 60,
	"lvl" : 40,
	"skill_name" : "���Ź��",
        "damage_type" : "����"
]),
([	"action" : "$N��ϥ������һʽ�����ޱߡ���������ȭ���⣬����Ĵֱָ����ңң����$nһ��",
	"force" : 480,
        "dodge" : 40,
        "parry" : 30,
	"damage": 90,
	"lvl" : 60,
	"skill_name" : "���ޱ�",
        "damage_type" : "����"
])
});

int valid_enable(string usage) { return usage=="finger" || usage=="parry"; }

int valid_combine(string combo) { return combo=="banruo-zhang"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("��һָ��������֡�\n");
	if ((int)me->query_skill("hunyuan-yiqi", 1) < 20)
		return notify_fail("��Ļ�Ԫһ������򲻹����޷�ѧһָ����\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������̫�����޷���һָ����\n");
	return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
	level   = (int) me->query_skill("yizhi-chan",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 30)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("�������������һָ����\n");
	me->receive_damage("qi", 30);
	me->add("neili", -10);
	return 1;
}
string perform_action_file(string action)
{
	return __DIR__"yizhi-chan/" + action;
}
