<div class="container fin">
  <div class="col-xs-12 apartment-menu zero-padding">
    <div class="col-xs-3 apartment-title zero-padding">
      <?php print $title_number;?>
    </div>
    <div class="col-xs-9 zero-padding">
      <ul class="apartment-tabs" role="tablist">
        <li role="presentation" class="active">
          <a href="#layout"  role="tab" data-toggle="tab" aria-controls="home" aria-expanded="true">
            <?php print t('Plan');?>
          </a>
        </li>
        <li role="presentation" class="">
          <a href="#layout-area" role="tab" data-toggle="tab" aria-controls="profile" aria-expanded="false">
            <?php print t('Location on the floor');?>
          </a>
        </li>
        <li role="presentation" class="">
          <a href="#layout-home" role="tab" data-toggle="tab" aria-controls="profile" aria-expanded="false">
            <?php print t('Location of the house');?>
          </a>
        </li>
        <li role="presentation" class="">
          <a href="#credit" role="tab" data-toggle="tab" aria-controls="profile" aria-expanded="false">
            <?php print t('mortgage');?>
          </a>
        </li>
      </ul>
    </div>
  </div>

  <div class="col-xs-12 zero-padding apartment-status-block">
    <div class="col-xs-1 status-icon">
      <?php print $image_status;?>
    </div>
    <div class="col-xs-6 apartment-status-body apartment-status-free">
      <?php print $status_text;?>
    </div>
    <div class="col-xs-6 bad-button-block">
      <?php print $link_modal_book;?>
    </div>
  </div>

</div>


<div class="container fin margin-bottom">

  <div class="col-xs-1 apartment-buttons-block zero-padding">
    <div class="col-xs-12 apartment-button">
      <?php print $add_comparison;?>
    </div>
    <div class="col-xs-12 apartment-button">
      <a data-toggle="modal" data-target=".modal_id">
        <img src="images/but2.svg" class="but1">
        <img src="images/but2h.svg" class="but1h" id="bankh">
        <div class="tip-button" id="bank">
          Получить ID квартиры
        </div>
      </a>
    </div>
    <div class="col-xs-12 apartment-button">
      <a href="#" data-toggle="modal" data-target=".modal_docs">
        <img src="images/but3.svg" class="but1">
        <img src="images/but3h.svg" class="but1h" id="documentsh">
        <div class="tip-button" id="documents">
          Получить документы
        </div>
      </a>
    </div>
  </div>

  <div class="col-xs-11 zero-pading tab-content apartment-body">
    <div role="tabpanel" class="tab-pane fade active in" id="layout" aria-labelledby="home-tab">
      <div class="col-xs-8 zero-padding apartment-plan">
        <img src="images/floor7.png" class="apartment-image-vertical">
      </div>
      <div class="col-xs-4 zero-padding apartment-text">
        <h3>Тип</h3>
        <p>1 комнатная студия</p>
        <h3>Цена</h3>
        <p>2 500 000 руб.</p>
        <h3>Расположение</h3>
        <p>Номер секции: 3</p>
        <p>Этаж: 7</p>
        <p>Номер квартиры: 337</p>
        <h3>Площади</h3>
        <p>Общая площадь: 25,83 м2</p>
        <p>Жилая площадь: 18,83 м2</p>
        <p>Площадь кухни: ---</p>
        <p>Площадь лоджии: 5,88 м2</p>
        <h3>Адрес</h3>
        <p>Заельцовский район</p>
      </div>
    </div>
    <div role="tabpanel" class="tab-pane fade" id="layout-area" aria-labelledby="profile-tab">
      <div class="col-xs-8 zero-padding apartment-plan">
        <img src="images/floor3.jpg" class="apartment-image-vertical">
      </div>
      <div class="col-xs-4 zero-padding apartment-text">
        <h3>Тип</h3>
        <p>1 комнатная студия</p>
        <h3>Цена</h3>
        <p>2 500 000 руб.</p>
        <h3>Расположение</h3>
        <p>Номер секции: 3</p>
        <p>Этаж: 7</p>
        <p>Номер квартиры: 337</p>
        <h3>Площади</h3>
        <p>Общая площадь: 25,83 м2 Общая площадь: 25,83 м2 Общая площадь: 25,83 м2</p>
        <p>Жилая площадь: 18,83 м2</p>
        <p>Площадь кухни: ---</p>
        <p>Площадь лоджии: 5,88 м2</p>
        <h3>Адрес</h3>
        <p>Заельцовский район</p>
      </div>
    </div>
    <div role="tabpanel" class="tab-pane fade" id="layout-home" aria-labelledby="profile-tab">
      <div class="col-xs-8 zero-padding apartment-plan">
        <img src="images/floor8.png" class="apartment-image-vertical">
      </div>
      <div class="col-xs-4 zero-padding apartment-text">
        <h3>Тип</h3>
        <p>1 комнатная студия</p>
        <h3>Цена</h3>
        <p>2 500 000 руб.</p>
        <h3>Расположение</h3>
        <p>Номер секции: 3</p>
        <p>Этаж: 7</p>
        <p>Номер квартиры: 337</p>
        <h3>Площади</h3>
        <p>Общая площадь: 25,83 м2</p>
        <p>Жилая площадь: 18,83 м2</p>
        <p>Площадь кухни: ---</p>
        <p>Площадь лоджии: 5,88 м2</p>
        <h3>Адрес</h3>
        <p>Заельцовский район</p>
      </div>
    </div>

    <div  role="tabpanel" id="credit" aria-labelledby="profile-tab" class="col-xs-11 develop-complex zero-padding tab-pane fade margin-top-70">
      <a href="" class="col-xs-4 develop-complex-item zero-padding banks-img">
        <img src="images/sberbank.png">
      </a>
      <a href="" class="col-xs-4 develop-complex-item zero-padding banks-img">
        <img src="images/mdmbank.png">
      </a>
      <a href="" class="col-xs-4 develop-complex-item zero-padding banks-img">
        <img src="images/vtbbank.png">
      </a>
      <a href="" class="col-xs-4 develop-complex-item zero-padding banks-img">
        <img src="images/sberbank.png">
      </a>
      <a href="" class="col-xs-4 develop-complex-item zero-padding banks-img">
        <img src="images/mdmbank.png">
      </a>
      <a href="" class="col-xs-4 develop-complex-item zero-padding banks-img">
        <img src="images/vtbbank.png">
      </a>
    </div>
  </div>
</div>
