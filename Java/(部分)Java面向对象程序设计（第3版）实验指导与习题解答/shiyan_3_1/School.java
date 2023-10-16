// School.java
public class School {
    String schoolName;
    InnerNewspaper newspaper;
    public School() {
        this("某某大学");
    }


    public School(String s) {
        newspaper=new InnerNewspaper();
        String[] content = {"学校举办迎新会.", "机械系获得机器人大赛冠军.", "计算机学院召开学生会换届大会."};
        schoolName = s;
        newspaper.setContent(content);
    }

    public void showNews() {
        newspaper.showContent();
    }

    class InnerNewspaper {
        String[] content;
        String paperName = "校新闻周报";

        void setContent(String[] s) {
            content = s;
        }

        public void showContent() {
            System.out.println(schoolName);
            for (int i = 0; i < content.length; i++) {
                System.out.println(content[i]);
            }
        }
    }
}
