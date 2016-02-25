/*
 *	@Package : WODPRESS XMLRPC 
 *  @Author : Pham Van Diep
 * 	@Contact : pndhainam@hotmail.com
 */

#include "taxonomy.h"
Taxonomy::Taxonomy(){
	Userblog user;
	QString host = user.Userblog_get_blog_host();
	QString path = user.Userblog_get_blog_path();
	int port = user.Userblog_get_blog_port();
	QString blogid = user.Userblog_get_blog_id();
	QString username = user.Userblog_get_blog_username();
	QString pass = user.Userblog_get_blog_password();
	this->tablename = "taxonomy";
	this->Taxonomy_db = new Database();
	this->Taxonomy_wp = new Wordpress(host,path,port,username,pass);
	this->Taxonomy_wp->Base_set_blog_id(blogid);
	//class have 14 variable
	this->size = 7;
	connect(this->Taxonomy_wp,SIGNAL(Wordpress_OK(QVariant)),this,SLOT(Taxonomy_get_taxonomy_ok(QVariant)));
	connect(this->Taxonomy_wp,SIGNAL(Wordpress_FAILED(int ,QString)),this,SLOT(Taxonomy_get_taxonomy_failed(int ,QString)));	
}
Taxonomy::~Taxonomy(){
	delete this->Taxonomy_wp;
	delete this->Taxonomy_db;
}
//get
QString Taxonomy::Taxonomy_get_name(){return this->name ;}
QString Taxonomy::Taxonomy_get_label(){return this->label ;}
bool Taxonomy::Taxonomy_get_hierarchical(){return this->hierarchical ;}
bool Taxonomy::Taxonomy_get_public(){return this->_public ;}
bool Taxonomy::Taxonomy_get_show_ui(){return this->show_ui ;}
bool Taxonomy::Taxonomy_get_builtin(){return this->builtin ;}
QString Taxonomy::Taxonomy_get_labels(){return this->labels ;}
QString Taxonomy::Taxonomy_get_cap(){return this->cap ;}
QString Taxonomy::Taxonomy_get_object_type(){return this->object_type ;}
//set
void Taxonomy::Taxonomy_set_name(QString name){this->name = name ;}
void Taxonomy::Taxonomy_set_label(QString label){this->label = label ;}
void Taxonomy::Taxonomy_set_hierarchical(bool hierarchical){this->hierarchical = hierarchical ;}
void Taxonomy::Taxonomy_set_public(bool _public){this->_public = _public ;}
void Taxonomy::Taxonomy_set_show_ui(bool show_ui){this->show_ui = show_ui ;}
void Taxonomy::Taxonomy_set_builtin(bool builtin){this->builtin = builtin ;}
void Taxonomy::Taxonomy_set_labels(QString labels){this->labels = labels ;}
void Taxonomy::Taxonomy_set_cap(QString cap){this->cap = cap ;}
void Taxonomy::Taxonomy_set_object_type(QString object_type){this->object_type = object_type ;}

void Taxonomy::Taxonomy_get_taxonomy(){
	this->Taxonomy_wp->Wordpress_gettaxonomies();
}
	
void Taxonomy::Taxonomy_get_taxonomy_ok(QVariant result){
	Labels lb;
	Cap caps;
	this->size = this->size + lb.Labels_get_size() + caps.Cap_get_size();
	QList<QStringList> list;
	list = MVariant(result).get_qlistqstringlist();
	QStringList what;
	this->Taxonomy_db->Database_select(this->tablename);
	int id = this->Taxonomy_db->Database_num_rows();
	int i = 0;
	while(i < list.size()){
		QList<QStringList> sublist = list.mid(i,this->size);
		foreach(QStringList item,sublist){
			if(item.at(0).compare("_builtin") == 0){
				this->builtin = item.at(1).toInt();
			}
			if(item.size() == 3){
				if(item.at(0).compare("labels") == 0){
					lb.Labels_set_add_new_item(item.at(2));
				}
				if(item.at(0).compare("cap") == 0){
					caps.Cap_set_assign_terms(item.at(2));
				}
			}
			//set cap
			if(item.at(0).compare("delete_terms") == 0){
				caps.Cap_set_delete_terms(item.at(1));
			}
			if(item.at(0).compare("edit_terms") == 0){
				caps.Cap_set_edit_terms(item.at(1));
			}
			if(item.at(0).compare("manage_terms") == 0){
				caps.Cap_set_manage_terms(item.at(1));
			}
			if(item.at(0).compare("hierarchical") == 0){
				this->hierarchical = item.at(1).toInt();
			}
			if(item.at(0).compare("label") == 0){
				this->label = item.at(1);
			}
			//set labels
			if(item.at(0).compare("add_or_remove_items") == 0){
				lb.Labels_set_add_or_remove_items(item.at(1));
			}
			if(item.at(0).compare("all_items") == 0){
				lb.Labels_set_all_items(item.at(1));
			}
			if(item.at(0).compare("choose_from_most_used") == 0){
				lb.Labels_set_choose_from_most_used(item.at(1));
			}
			if(item.at(0).compare("edit_items") == 0){
				lb.Labels_set_edit_item(item.at(1));
			}
			if(item.at(0).compare("menu_name") == 0){
				lb.Labels_set_menu_name(item.at(1));
			}
			//cai nay cua label bi trung voi
			//name cua taxonomy
			if(item.at(0).compare("name") == 0){
				lb.Labels_set_name(item.at(1));
			}
			if(item.at(0).compare("name_admin_bar") == 0){
				lb.Labels_set_name_admin_bar(item.at(1));
			}
			if(item.at(0).compare("new_item_name") == 0){
				lb.Labels_set_new_item_name(item.at(1));
			}
			if(item.at(0).compare("parent_item") == 0){
				lb.Labels_set_parent_item(item.at(1));
			}
			if(item.at(0).compare("parent_item_colon") == 0){
				lb.Labels_set_parent_item_colon(item.at(1));
			}
			if(item.at(0).compare("popular_items") == 0){
				lb.Labels_set_popular_items(item.at(1));
			}
			if(item.at(0).compare("search_items") == 0){
				lb.Labels_set_search_items(item.at(1));
			}
			if(item.at(0).compare("separate_items_with_commas") == 0){
				lb.Labels_set_separate_items_with_commas(item.at(1));
			}
			if(item.at(0).compare("singular_name") == 0){
				lb.Labels_set_singular_name(item.at(1));
			}
			if(item.at(0).compare("update_item") == 0){
				lb.Labels_set_update_item(item.at(1));
			}
			if(item.at(0).compare("view_item") == 0){
				lb.Labels_set_view_item(item.at(1));
			}
			if(item.at(0).compare("public") == 0){
				this->_public = item.at(1).toInt();
			}
			if(item.at(0).compare("show_ui") == 0){
				this->show_ui = item.at(1).toInt();
			}
			if(item.at(0).compare("name") == 0){
				this->name = item.at(1);
			}					
			if(item.at(0).compare("object_type") == 0){
				this->object_type = item.at(1);
			}															
		}
		caps.Cap_insert_db();
		this->cap = QString::number(caps.Cap_get_id());
		lb.Labels_insert_db();
		this->labels = QString::number(lb.Labels_get_id());
		id++;
		what<<QString::number(id)<<this->name<<this->label<<QString::number(this->hierarchical)\
		<<QString::number(this->_public)<<QString::number(this->show_ui) \
		<<QString::number(this->builtin)<<this->labels<<this->cap<<this->object_type;
		this->Taxonomy_db->Database_insert(this->tablename,what);
		what.clear();
		i = i + this->size;
	}
		
}
void Taxonomy::Taxonomy_get_taxonomy_failed(int code ,QString msg){
	QMessageBox::critical(NULL,"Error",QString::number(code) + " => " + msg);
}
