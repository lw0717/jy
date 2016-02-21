// ChengChaoFeng.c
// pal 1997.05.11

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
inherit F_UNIQUE;

string ask_me();

void create()
{
    set_name("������", ({ "cheng chaofeng", "cheng", "chaofeng", }));
	set("long",
        "����һλ�彡��ţ�Ĵ󺺣�����һ���ײ����ۡ�\n"
        "���������ϵļ��ⰼ��͹͹���̸����ڣ������书��Ϊ��ǳ��\n"
	);

    	set("title",HIG "����" HIR "��ȸ̳" NOR "̳��");

	set("gender", "����");
	set("attitude", "friendly");
//    set("class", "bonze");

    set("age", 45);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 450);
	set("max_jing", 300);
	set("neili", 600);
	set("max_neili", 600);
	set("jiali", 50);
	set("combat_exp", 50000);
	set("score", 100);

	set_skill("force", 70);
	set_skill("hunyuan-yiqi", 70);
	set_skill("dodge", 70);
	set_skill("shaolin-shenfa", 70);
	set_skill("finger", 68);
	set_skill("nianhua-zhi", 68);
	set_skill("parry", 70);
	set_skill("sword", 80);
	set_skill("damo-jian", 80);
	set_skill("buddhism", 70);
	set_skill("literate", 70);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("finger", "nianhua-zhi");
	map_skill("parry", "damo-jian");
	map_skill("sword", "damo-jian");

	prepare_skill("finger", "nianhua-zhi");

    create_family("����", 4, "����̳̳��");

	set("inquiry", ([
		"����" :    (: ask_me :),
	]));

	setup();

//        carry_object("/d/shaolin/obj/tiexigua")->wield();
        carry_object("/d/mingjiao/obj/baipao")->wear();
}

#include "/kungfu/class/mingjiao/tanzhu.h"

string ask_me()
{
	return "������ �������ֲ�ȱ���� ǰ�����ǲ��Ǹ�����һ�����飬������ʲ��ĸ����𣿣�";
}