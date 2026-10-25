package Main.dto;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@Data
@AllArgsConstructor
@NoArgsConstructor
public class CreateQuizInputDto {
    private String uniqueCode;
    private String topic;
    private Integer noOfQuestions;
}
