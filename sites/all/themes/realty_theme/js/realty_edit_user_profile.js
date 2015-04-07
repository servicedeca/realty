(function ($) {
  Drupal.behaviors.realtyEditUserprofile = {
    attach: $(function(){
      var butEdit,
          inputEditName,
          inputEditPhone,
          inputEditMail;

      var init = function() {
        butEdit = document.getElementsByClassName('profile-edit');
        inputEditPhone = document.getElementById('profile-phone');
        inputEditName = document.getElementById('profile-name');
        inputEditMail = document.getElementById('profile-mail');
      }

      var editValue = function () {
        $(document).on('click', '.profile-edit', function() {
          console.log(inputEditName.value);
          if (inputEditName.value === '' || inputEditPhone.value === '' || inputEditMail === '') {

          }
          else {
            $.ajax({
              url: '/edit_user_profile',
              type: 'POST',
              data: {
                name: inputEditName.value,
                mail: inputEditMail.value,
                phone: inputEditPhone.value
              },
              success: function(response) {
                if (response === '1') {
                  $('#h-name').html(inputEditName.value);
                  $('#h-mail').html(inputEditMail.value);
                  $('#h-phone').html(inputEditPhone.value);
                  $('.close-modal').trigger('click');
                }
                else {
                  alert('error');
                }
              },
              error: function(response) {
                alert('false');
              }
            });
          }
        });
      }

      var closeModal = function() {
        $(document).on('click', '.close-modal', function() {

          inputEditName.value = $('#h-name').html();
          inputEditMail.value = $('#h-mail').html();
          inputEditPhone.value = $('#h-phone').html();

        });
      }

      init();
      editValue();
      //closeModal();
    })
  }

}(jQuery));